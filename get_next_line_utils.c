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

	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
	size_t	len;

	len = count * size;
	ptr = (char *)malloc(len);
	if (ptr)
	{
		while (len > 0)
		{
			*ptr = 0;
			ptr++;
			len--;
		}
		return (ptr);
	}
	return (NULL);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (srclen);
	if (dstsize > 0)
	{
		while (i != dstsize - 1)
		{
			if (src[i] != '\0')
			{
				dst[i] = src[i];
			}
			else
			{
				break;
			}
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
