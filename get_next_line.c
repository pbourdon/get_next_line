/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 23:18:43 by pbourdon          #+#    #+#             */
/*   Updated: 2016/01/25 19:17:51 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

static char		*read_alpha(int const fd, char *tmp, int *check)
{
	char		tmp2[BUFF_SIZE + 1];
	char		*frii;

	*check = read(fd, tmp2, BUFF_SIZE);
	tmp2[*check] = '\0';
	frii = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(frii);
	return (tmp);
}

int				save_lines(int *check, char **tmp, int const fd, char **line)
{
	*check = 1;
	if (fd < 0 || line == NULL)
		return (1);
	if (!*tmp)
	{
		*tmp = malloc(sizeof(1));
		if (*tmp)
			*tmp[0] = '\0';
		else
			return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*tmp;
	char			*cursor;
	int				check;

	if (save_lines(&check, &tmp, fd, line))
		return (-1);
	while (check > 0)
	{
		if ((cursor = ft_strchr(tmp, '\n')) != NULL)
		{
			*cursor = '\0';
			*line = ft_strdup(tmp);
			ft_memmove(tmp, cursor + 1, ft_strlen(cursor + 1) + 1);
			return (1);
		}
		tmp = read_alpha(fd, tmp, &check);
	}
	if (tmp != (cursor = ft_strchr(tmp, '\0')))
	{
		printf ("here");
		*line = ft_strdup(tmp);
		ft_memmove(tmp, cursor + 1, ft_strlen(cursor + 1) + 1);
		return (1);
	}
	return (check);
}
/*
   int		main(void)
   {
   char	*line;
   int		fd;
   char	*filename;
   int		ret;

   filename = "test2.txt";
   fd = open(filename, O_RDONLY);
   while ((ret = get_next_line(fd, &line)) > 0)
   {
   printf ("%d\n", ret);
   }
   }
   */
