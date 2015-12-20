/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:59:20 by pbourdon          #+#    #+#             */
/*   Updated: 2015/12/16 17:03:31 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		get_next_line(int const fd, char **line)
{
	char		buf[20];
	size_t		nbytes;
	ssize_t		bytes_read;

	nbytes = 19;
//	printf("%s\n", line[1]);
	read(fd, buf, 19);
//	buf[nbytes] = '\0';
	printf("%s", buf);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	fd = open(argv[1], O_RDONLY);

	get_next_line(fd, argv);
	
	return (0);
}

