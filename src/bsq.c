/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-go <cruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:00:00 by usuario           #+#    #+#             */
/*   Updated: 2025/03/11 23:10:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_map(t_map *map)
{
	unsigned int	i;

	if (map && map->map)
	{
		i = 0;
		while (i < map->lines)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	free_sol_map(map);
}

void	process_all_map_n_show(t_map *map)
{
	alloc_sol_map(map);
	init_map(map);
	solve(map);
	printsol(map);
	free_map(map);
}

int	process_map_file(char *file)
{
	unsigned int	offset;
	t_map			*map;
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "map error\n", 10);
		return (1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		return (1);
	}
	offset = readparams(map, fd, file);
	if (!parse_and_build_map(map, file, offset))
	{
		free_map(map);
		write(2, "map error\n", 10);
		return (1);
	}
	process_all_map_n_show(map);
	return (0);
}

int	process_map_stdin(void)
{
	t_map			*map;
	unsigned int	offset;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	offset = readparams_stdin(map);
	if (offset == 0)
	{
		free(map);
		write(2, "map error\n", 10);
		return (1);
	}
	process_all_map_n_show(map);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	result;

	if (argc == 1)
		return (process_map_stdin());
	i = 1;
	result = 0;
	while (i < argc)
	{
		if (i > 1)
			write(1, "\n", 1);
		result |= process_map_file(argv[i]);
		i++;
	}
	return (result);
}
