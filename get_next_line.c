#include "get_next_line.h"

char *ft_read(int fd, char *buffer)
{
	char *line;
	int bytes_read;

	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_read = 0;
	while (ft_strchr(buffer, '\n') == 0)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		line[bytes_read] = '\0';
	}
	printf("%i\n", bytes_read);
	return (line);
}

char *get_next_line(int fd)
{
	static char *stash[1024];
	char *line = NULL;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_calloc(1, 1);
	if (stash[fd] == NULL)
		return (NULL);
	stash[fd] = ft_read(fd, stash[fd]);
	return (line);
}