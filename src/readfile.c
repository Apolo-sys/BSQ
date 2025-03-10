#include "bsq.h"

unsigned int	get_file_len(int fd)
{
	unsigned int	l;
	char		b[1];

	l = 0;
	while (read(fd, b, 1) == 1)
		l++;
	return (l);
}

unsigned int readparams(t_map *map, int fd, char *file)
{
	unsigned int l;
	char b[2];
	char *fline;
	char *temp;

	l = 0;
	while (read(fd, b, 1) == 1 && *b != '\n')
		l++;
	close(fd);
	fd = open(file, O_RDONLY);
	printf("LINESIZE: %u\n", l);
	fline = (char *)malloc(l + 1);
	temp = fline;
	read(fd, fline, l);
	fline[l] = 0;
	printf("LINE: %s\n", fline);
	map->lines = ft_atoi(fline);
	while (*fline >= '0' && *fline <= '9')
		fline++;
	map->empty = *fline++;
	map->obj = *fline++;
	map->full = *fline;
	free(temp);
	close(fd);
	return (l);
}
