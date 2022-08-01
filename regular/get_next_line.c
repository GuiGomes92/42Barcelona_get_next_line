/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:47:09 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/08/01 19:57:03 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_remove_line(char *buffer)
{
	int i;
	char *newbuffer;
	int start;

	i = 0;
	if (!buffer)
		return (NULL);
	if (buffer[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	start = ft_linelen(buffer) + 1;
	newbuffer = ft_calloc(ft_strlen(buffer) - start + 1, sizeof(char));
	if (newbuffer == NULL)
		return (NULL);
	while (buffer[start + i] != '\0')
	{
		newbuffer[i] = buffer[start + i];
		//printf("%c\n",newbuffer[i]);
		i++;
	}
	newbuffer[i] = buffer[start + i];
	//printf("%s\n", newbuffer);
	free(buffer);
	return (newbuffer);
}

char *ft_extract_line(char *buffer)
{
	char *line;
	size_t len;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	len = ft_linelen(buffer) + 1;
	line = ft_calloc(len, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, len);
	//printf("%s\n", line);
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
		new_buffer = ft_strjoin(buffer, reading);
		free(buffer);
		buffer = new_buffer;
	}
	if (bytes_read == -1)
		return (NULL);
	free(reading);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *stash;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, 1);
	if (stash == NULL)
		return (NULL);
	stash = ft_read(fd, stash);
	//printf("READ: %s\n", stash);
	line = ft_extract_line(stash);
	//printf("EXTRACT: %s\n", line);
	stash = ft_remove_line(stash);
	//printf("STASH: %s\n", stash);
	return (line);
}
