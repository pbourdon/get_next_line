/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 23:19:13 by pbourdon          #+#    #+#             */
/*   Updated: 2016/02/08 20:32:30 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9
# include <string.h>

void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *s1);
int			get_next_line(const int fd, char **line);
void		*ft_memmove(void *dest, const void *source, size_t len);
size_t		ft_strlen(const char *str);

#endif
