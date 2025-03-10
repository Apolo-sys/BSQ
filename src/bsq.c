#include "bsq.h"

int	main(int argc, char **argv)
{
	char	*file;

	if (argc != 2)
		return (1);
	file = argv[1];

	t_map *map =  malloc(sizeof(t_map));

	int l = readparams(map, open(file, O_RDONLY), file);
	l = 0;
}
