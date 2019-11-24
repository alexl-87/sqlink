#include <linux/module.h>
#include <linux/init.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEV_CAPACITY 1
static dev_t my_dev;
static struct cdev my_cdev;

static ssize_t my_null_write(struct file* filp, const char __user * buf, size_t sx, loff_t* off)
{
	pr_info("Inside write function\n");
	return sx;
}

static struct file_operations my_ops = 
{
	.write = my_null_write
};

static int __init null_init(void)
{
	int retval = 0;
	pr_info("*** Init my useless module ***\n");

	retval = alloc_chrdev_region(&my_dev, 0, DEV_CAPACITY, "my_null");
	if(retval)
	{
		pr_info("*ERROR* alloc_chrdev_region\n");
		return 1;
	}
	cdev_init(&my_cdev, &my_ops);
	retval = cdev_add(&my_cdev, my_dev, DEV_CAPACITY);

	return 0;
}

static void __exit null_exit(void)
{
	unregister_chrdev_region(my_dev, DEV_CAPACITY);
	pr_info("*** Exit my useless module ***\n");
}

module_init(null_init);
module_exit(null_exit);

