#ifndef BSQ_H
# define BSQ_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_map
{
	unsigned int	lines;
	unsigned int	linelen;
	char			empty;
	char			obj;
	char			full;
	char			**map;
}	t_map;

unsigned int	readparams(t_map *map, int fd, char *file);
void	putstr(char *str);
int		ft_atoi(char *str);
char	*trim(char *str);
void	parse_line(char *line);
void	*parse_map(char *filename);
#endif
