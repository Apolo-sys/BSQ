#include "bsq.h"

void	putstr(char *str)
{
	while (*str++)
		write(1, str, 1);
	write(1, "\n", 1);
}
