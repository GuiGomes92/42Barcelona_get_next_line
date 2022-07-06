#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
char *get_next_line(int fd)
{
	char buf[30];
	size_t bytes_read;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);	
	bytes_read = read(fd, buf, 1);
	printf("%s\n", buf);
	printf("%zd",bytes_read);
	return (0);
}

int	main(void)
{
	int fd;

	fd = open("files/text.txt", O_RDONLY);
	get_next_line(fd);
}
