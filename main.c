#include "get_next_line.h"

int main(void)
{
	int fd;
	int fd2;

	fd = open("files/text.txt", O_RDONLY);
	fd2 = open("files/43_nl.txt", O_RDONLY);
	char *line = get_next_line(fd);
	char *line2 = get_next_line(fd2);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	while (line2 != NULL)
      {
          printf("%s", line2);
          line2 = get_next_line(fd2);
     }  
}
