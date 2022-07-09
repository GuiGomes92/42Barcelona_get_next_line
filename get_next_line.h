#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd);
void *ft_calloc(size_t count, size_t size);
char *ft_strchr(const char *s, int c);
int ft_strlen(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_read(int fd, char *buffer);

#endif
