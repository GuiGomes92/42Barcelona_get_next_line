#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line = NULL;
	int			bytes_read;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (NULL);
	if
	bytes_read = read(fd, stash[0], BUFFER_SIZE);
	printf("%s", stash[0]);
	return (line);
}
