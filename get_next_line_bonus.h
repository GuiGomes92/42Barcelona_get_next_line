/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:47:20 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/08/13 13:08:07 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s, int c);
int		ft_linelen(char *s);
char	*ft_strjoin(char*s1, char*s2);
char	*ft_read(int fd, char *buffer);
char	*ft_extract_line(char *buffer);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_strlen(char *s);
char	*ft_remove_line(char *buffer);

#endif
