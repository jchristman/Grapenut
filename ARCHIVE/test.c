/*
 * Run the preprocessor on this with
 * 	`gcc -E test.c`
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main (void)
{
	int fd = open("/tmp/test", O_CREAT | O_RDWR, 00777);

	printf("%x, %x, %x, %x\n", O_CREAT, O_RDONLY, O_WRONLY, O_RDWR);

	close(fd);

	return 0;
}
