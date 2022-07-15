#include "get_next_line.h"

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
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

char *ft_strchr(const char *s, int c)
{
	char newC;

	newC = (char)c;
	while (*s != '\0' && *s != newC)
		s++;
	if (*s == newC)
		return ((char *)s);
	return (0);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;
	int i;
	int j;

	ptr = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
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
		*(ptr + i) = 0;
		i++;
	}
	return (ptr);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
	*(dst + i - 1) = '\0';
	return (len);
}
