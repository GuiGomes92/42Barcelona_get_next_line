#include "get_next_line.h"

char *ft_extract_line(char *buffer)
{
	char *line;
	size_t len;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	len = ft_linelen(buffer) + 1;
	line = ft_calloc(len, sizeof(char));
	ft_strlcpy(line, buffer, len);
	return (line);
}

char *ft_read(int fd, char *buffer)
{
	char *reading;
	char *new_buffer;
	int bytes_read;

	if (ft_strchr(buffer, '\n') != 0)
		return (buffer);
	reading = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (reading == NULL)
		return (NULL);
	while (ft_strchr(reading, '\n') == 0)
	{
		bytes_read = read(fd, reading, BUFFER_SIZE);
		if (bytes_read < 1)
			break;
		reading[bytes_read] = '\0';
		new_buffer = ft_strjoin(buffer, reading);
		free(buffer);
		buffer = new_buffer;
	}
	free(reading);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *stash[1024];
	char *line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_calloc(1, 1);
	if (stash[fd] == NULL)
		return (NULL);
	stash[fd] = ft_read(fd, stash[fd]);
	line = ft_extract_line(stash[fd]);
	printf("%s\n", stash[fd]);
	printf("Middle\n");
	printf("%s\n", line);
	return (line);
}