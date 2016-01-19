#include "ft_get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long a;
	char *str_src;
	char *str2_dest;

	a = 0;
	if (n == 0 || dest == src)
			return (dest);
	str_src = (char *)src;
	str2_dest = (char *)dest;
	while (a < n)
	{
		str2_dest[a] = str_src[a];
		a++;
	}
	return (dest);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int		a;
	
	a = 0;
	while (src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = src[a];
	return (dst);
}

char		*ft_strcat(char *s1, const char *s2)
{
	ft_memcpy(s1 + strlen(s1), s2, strlen(s2) + 1);
	return (s1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);	
}

char		*ft_strchr(const char *s, int c)
{
	char *s1;
	int	a;
	s1 = (char *)s;
	a = 0;
	while (s1[a] != '\0')
	{
		if (s1[a] == c)
			return (s1 + a);
		a++;
	}
	if (s1[a] == c)
		return (s1 + a);
	return (NULL);
}

char		*ft_strdup(char *s1)
{
	int	a;
	char	*new;

	new = (char *)malloc(sizeof(char) *(strlen(s1) + 1));
	if (!new)
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		new[a] = s1[a];
		a++;
	}
	new[a] = '\0';
	return (new);
}

char		*read_alpha(int const fd, char *tmp, int *check)
{
	char		tmp2[BUFFER + 1];
	char		*frii;

	*check = read(fd, tmp2, BUFFER);
	tmp2[*check] = '\0';
	frii = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(frii); 
	return (tmp);

}

int		get_next_line(int const fd, char ** line)
{
	int		test;
	static char	*tmp;
	char		*cursor;
	int		check;

	check = 1;
	cursor = 0;
	if (!tmp)
	{
		tmp = malloc(sizeof(1));
		tmp[0] = '\0';
	}
	while (check > 0)
	{
		if ((cursor = ft_strchr(tmp, '\n')) != NULL)
		{
			*cursor = '\0';
			*line = strdup(tmp);
			memmove(tmp, cursor + 1, strlen(cursor + 1) + 1);
		//	printf("%d is check ", check);
			return (1);
		}
		tmp = read_alpha(fd, tmp, &check);
	}
	if (check == 0 && tmp)
			*line = strdup(tmp);
	return (check);
}



int		main(int argc, char **argv)
{
	char	*line;
	int	retur;
	int	fd;

	fd = 0;

	retur = 0;
	fd = open(argv[1], O_RDONLY);
	retur = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("%d is the return of gnl\n", retur);
	retur = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("%d is the return of gnl", retur);
	return (0);
}
