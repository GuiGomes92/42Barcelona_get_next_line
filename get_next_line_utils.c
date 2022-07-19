/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:47:35 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/07/19 20:51:42 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_linelen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char *ft_strchr(char *s, int c)
{
	char newC;

	newC = (char)c;
	while (*s != '\0' && *s != newC)
		s++;
	if (*s == newC)
		return ((char *)s);
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *ptr;
	int i;
	int j;
	int len;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	ptr = (char *)malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count)
	{
		*(ptr + i) = '\0';
		i++;
	}
	return (ptr);
}

size_t ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i < dstsize)
	{
		if(*(src + i) == '\0')
		{
			*(dst + i) = *(src + i);
			return (len);
		}
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i - 1) = '\n';
	//*(dst + i) = '\0';
	return (len);
}
