#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	char	*line;
	int		fd;
	char	*filename;
	int		ret;

	filename = "test2.txt";
	fd = open(filename, O_RDONLY);
	fd = 42999;
	ret = get_next_line(fd, &line);
	printf ("%d\n", ret);

}
