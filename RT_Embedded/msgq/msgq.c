#include "mq.h"
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>/*alloc_chrdev_region()
						struct inode*/
#include <linux/cdev.h>/*struct cdev*/
#include <linux/device.h>/*class_create()
							device_create()*/
#include <linux/slab.h> /*kmalloc()*/
#include <linux/list.h>
#include <sys/type.h>
#define MINOR_COUNT 8

/*STRUCTS*/
static struct cdev cdev_msgq;
static struct class *class_msgq;
static dev_t dev_msgq;

static struct q_message
{
	struct list_head node;
	char* data;
	int size;
};

static struct ipc_queue
{	
	struct device* msgq_dev;
	unsigned long msg_counter;
	struct list_head list;
};

static struct ipc_queue* msgq_list;
/***END OF STRUCTS***/

/*FILE OPERATIONS*/
static int open_ipc_msgq_dev(struct inode* ind, struct file* f)
{
	int msgq_number = iminor(ind)-MINOR(dev_msgq);
	pr_alert("ipc_msgq_dev: the_pipe_number - %d\n", msgq_number);
	f->private_data = msgq_list[msgq_number].msgq_dev;
	return 123;
}

static int release_ipc_msgq_dev(struct inode* ind, struct file* f)
{
	pr_alert("ipc_msgq_dev: TEST inside RELEASE function\n");
	return 321;
}

static long ipc_msgq_dev_ioctl(struct file* f, unsigned int num, unsigned long lon)
{
	
	pr_alert("ipc_msgq_dev: TEST inside IOCTL function\n");
	return 132;
}

/***END OF FILE OPERATIONS***/

static void ipc_msgq_ctor(struct ipc_queue* queue, struct device* dev)
{
	queue->msg_counter = 0;
	queue->msgq_dev = dev;
	INIT_LIST_HEAD(queue->list);
}

static struct file_operations file_ops = 
{
	.owner = THIS_MODULE,
	.open = open_ipc_msgq_dev,
	.release = release_ipc_msgq_dev,
	.unlocked_ioctl = ipc_msgq_dev_ioctl
};


static int __init msgq_init(void)
{
	int retval = 0;
	int i;
	pr_alert("ipc_msgq_dev: Inserting ipc_msgq_dev module\n");

	msgq_list = kmalloc(sizeof(struct ipc_queue)*MINOR_COUNT, GFP_KERNEL);
	if(!msgq_list)
	{
		pr_alert("ipc_msgq_dev: ***FAIL*** kmalloc()\n");
		goto ret_val_exit;
	}

	retval = alloc_chrdev_region(&dev_msgq, 0, MINOR_COUNT, "ipc_msgq_dev");
	if (retval != 0)
	{
		pr_alert("ipc_msgq_dev: ***FAIL*** alloc_chrdev_region()\n");
		goto alloc_chrdev_region_err;
	}

	pr_alert("ipc_msgq_dev: major = %d\n", MAJOR(dev_msgq));

	cdev_init(&cdev_msgq, &file_ops);
	retval = cdev_add(&cdev_msgq, dev_msgq, MINOR_COUNT);
	if (retval != 0)
	{
		pr_alert("ipc_msgq_dev: ***FAIL*** cdev_add()\n");
		goto cdev_add_err;
	}

	class_msgq = class_create(THIS_MODULE, THIS_MODULE->name);

	if (IS_ERR(class_msgq)) 
	{
		pr_alert("ipc_msgq_dev: ***FAIL*** class_create()\n");
		retval = PTR_ERR(class_msgq);
		goto class_create_err;
	}

	for (i = 0; i < MINOR_COUNT; ++i)
	{
		struct device* dev = device_create(	class_msgq, 
											NULL, 
											MKDEV(MAJOR(dev_msgq), MINOR(dev_msgq)+i), 
											NULL, 
											"%s%d", 
											THIS_MODULE->name,
											i);

		if (IS_ERR(dev))
		{
			pr_alert("ipc_msgq_dev: ***FAIL*** device_create() iteration %d\n", i);
			goto device_create_err;
		}

		ipc_msgq_ctor(&msgq_list[i], dev);	
	}

	goto ret_val_exit;

device_create_err:
	class_destroy(class_msgq);

class_create_err:
	cdev_del(&cdev_msgq);

cdev_add_err:
	unregister_chrdev_region(dev_msgq, MINOR_COUNT);

alloc_chrdev_region_err:
	kfree(msgq_list);

ret_val_exit:
	return retval;
}

static void __exit msqq_exit(void)
{
	int i = 0;
	pr_alert("ipc_msgq_dev: Removing msg queue module\n");
	
	pr_alert("ipc_msgq_dev: Devices destroy\n");
	for(;i < MINOR_COUNT; ++i)
	{
		device_destroy(class_msgq, 
						MKDEV(	MAJOR(dev_msgq), 
								MINOR(dev_msgq)+i));
	}
	
	pr_alert("ipc_msgq_dev: class_destroy\n");
	class_destroy(class_msgq);

	pr_alert("ipc_msgq_dev: cdev_del\n");
	cdev_del(&cdev_msgq);

	pr_alert("ipc_msgq_dev: unregister_chrdev_region\n");
	unregister_chrdev_region(dev_msgq, MINOR_COUNT);

	pr_alert("ipc_msgq_dev: kfree\n");
	kfree(msgq_list);
}

module_init(msgq_init);
module_exit(msqq_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("IPC message queue");
MODULE_AUTHOR("Alex");