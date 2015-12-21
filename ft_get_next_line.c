/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:59:20 by pbourdon          #+#    #+#             */
/*   Updated: 2015/12/21 08:59:45 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_get_next_line.h"



char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	int		l;
	int		i;
	int		j;
	char	*s3;

	i = 0;
	l = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	s3 = (char*)malloc(sizeof(char) * l);
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && j < n)
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

int		ft_find_c_in_str(char *str, char c)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return (-1);
		index++;
	}
	return (index);
}

int		get_next_line(int const fd, char **line)
{
	int			test;
	char		*tmp;
	char		*buff;
	int			index;

	index = 0;

	tmp = malloc(sizeof(*tmp) + BUFF_SIZE + 1);
	while ((test = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (test == -1)
			return (-1);
		index = ft_find_c_in_str(buff, '\n');
		if (index == -1)
		{
			printf("C");
			tmp = ft_strjoin(*line, buff);
			//free(*line);
			*line = tmp;
		}
		else
		{
			printf("dd");
			tmp = ft_strnjoin(*line, buff, index);
		//	free(*line);
			*line = tmp;
			ft_strcpy(buff, buff + index + 1);
		}
	}
	printf("%s\n", tmp);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	return (0);
}

