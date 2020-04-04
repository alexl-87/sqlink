#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
void ERR(int ret_val);
void print_test_file_info(struct stat* file_info);
void add_data(int fd, int mem_ammount, struct stat* file_info);
void print_mem_map();
void seek_forward(int fd, int offset, struct stat* file_info);
static int pos = 0;

int main(int argc, char const *argv[])
{
	blksize_t 	blk_size 	= -1;
	int 		root_fd 	= -1;
	int 		file_fd 	= -1;
	struct stat fs_info;
	struct stat file_info;

	root_fd = open("/", O_RDONLY);
	ERR(root_fd);

	ERR(fstat(root_fd, &fs_info));

	blk_size = fs_info.st_blksize;
	printf("\n> FS block size = %ld\n", blk_size);

	ERR(close(root_fd));

	file_fd = open("test_file", O_RDWR | O_CREAT,
								S_IRUSR | S_IWUSR | S_IRGRP |
								S_IWGRP | S_IROTH | S_IWOTH);
	ERR(file_fd);
	printf("\n> Test file created\n");

	ERR(fstat(file_fd, &file_info));
	print_test_file_info(&file_info);

	add_data(file_fd, blk_size, &file_info);
	add_data(file_fd, blk_size/2, &file_info);
	seek_forward(file_fd, blk_size, &file_info);
	seek_forward(file_fd, blk_size/2, &file_info);
	add_data(file_fd, 256, &file_info);

	ERR(close(file_fd));
	print_mem_map();

	return 0;
}

void ERR(int ret_val)
{
	if(ret_val < 0)
	{
		perror("error");
		exit(1);
	}
}

void print_test_file_info(struct stat* file_info)
{
	printf("\n> Current test file size: %ld bytes\n", file_info->st_size);
	printf("  Number of blocks allocated: %ld\n", file_info->st_blocks/8);
	printf("  Current file position: %d\n", pos);
}

void add_data(int fd, int mem_ammount, struct stat* file_info)
{
	int total = 0;
	int result = 0;
	int i = 0;
	char* data = malloc(mem_ammount);

	if(!data)ERR(-1);
	for(i = 0; i < mem_ammount; ++i) data[i] = 'c';

	while(total < mem_ammount)
	{
		result = write(fd, (void*)(data+total), mem_ammount-total);
		ERR(result);
		total+=result;
	}

	ERR(fsync(fd));
	ERR(fstat(fd, file_info));
	pos += total;
	printf("\n[%d bytes added to the test file]\n", total);
	print_test_file_info(file_info);
	free(data);
}

void seek_forward(int fd, int offset, struct stat* file_info)
{
	ERR(lseek(fd, offset, SEEK_CUR));
	printf("\n[lseek %d bytes applied from current position]\n", offset);
	pos+=offset;
	print_test_file_info(file_info);
}

void print_mem_map()
{
	printf( "\n-------------------------------------------------------------------------------------------------\n"
			"|///////FIRST BLOCK/////|///////SECOND BLOCK\t|\tTHIRD BLOCK\t|///\tFOURTH BLOCK\t|\n"
			"|///////0 bytes hole////|///////2048 bytes hole\t|\t4096 bytes hole\t|///\t256 bytes data\t|\n"
			"|///////4096 bytes data/|///////2048 bytes data\t|\to bytes data\t|///\t3840 bytes hole\t|\n"
			"-------------------------------------------------------------------------------------------------\n");
}