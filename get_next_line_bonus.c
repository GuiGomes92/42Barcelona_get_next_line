/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:47:09 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/08/13 13:39:31 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_remove_line(char *buffer)
{
	int		i;
	char	*newbuffer;
	int		start;

	i = 0;
	if (!buffer)
		return (NULL);
	start = ft_linelen(buffer) + 1;
	if (buffer[0] == '\0' || !buffer[start - 1])
	{
		free(buffer);
		return (NULL);
	}
	newbuffer = ft_calloc(ft_strlen(buffer) - start + 1, sizeof(char));
	if (newbuffer == NULL)
		return (NULL);
	while (buffer[start + i] != '\0')
	{
		newbuffer[i] = buffer[start + i];
		i++;
	}
	newbuffer[i] = buffer[start + i];
	free(buffer);
	return (newbuffer);
}

char	*ft_extract_line(char *buffer)
{
	char	*line;
	size_t	len;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	len = ft_linelen(buffer) + 2;
	line = ft_calloc(len, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, len);
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*reading;
	char	*new_buffer;
	int		bytes_read;

	if (ft_strchr(buffer, '\n') != 0)
		return (buffer);
	reading = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (reading == NULL)
		return (buffer);
	while (ft_strchr(reading, '\n') == 0)
	{
		bytes_read = read(fd, reading, BUFFER_SIZE);
		if (bytes_read < 1)
			break ;
		reading[bytes_read] = '\0';
		new_buffer = ft_strjoin(buffer, reading);
		free(buffer);
		buffer = new_buffer;
	}
	free(reading);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

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
	stash[fd] = ft_remove_line(stash[fd]);
	return (line);
}
