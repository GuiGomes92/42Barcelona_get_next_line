#include "get_next_line.h"

int main(void)
{
	int fd;

	fd = open("files/text.txt", O_RDONLY);
	while (get_next_line(fd) != 0)
		get_next_line(fd);
}
