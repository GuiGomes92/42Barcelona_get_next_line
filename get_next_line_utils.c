#include "get_next_line.h"

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
