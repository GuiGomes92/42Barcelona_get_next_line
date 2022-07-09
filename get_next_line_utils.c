#include "get_next_line.h"

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
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

void *ft_calloc(size_t count, size_t size)
{
	char *s1;
	size_t i;

	s1 = (char *)malloc(count * size);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		*(s1 + i) = 0;
		i++;
	}
	return (s1);
}
