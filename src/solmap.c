/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:10:29 by jaicastr          #+#    #+#             */
/*   Updated: 2025/03/11 23:10:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_sol_map(t_map *map)
{
	unsigned int	i;

	if (map && map->map_int)
	{
		i = 0;
		while (i < map->lines)
		{
			free(map->map_int[i]);
			i++;
		}
		free(map->map_int);
	}
	free(map);
}

void	alloc_sol_map(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	map->map_int = (int **)malloc(sizeof(int *) * map->lines);
	i = 0;
	while (i < map->lines)
	{
		map->map_int[i] = (int *)malloc(sizeof(int) * (map->cols + 1));
		if (!map->map_int[i])
		{
			j = 0;
			while (j < i)
			{
				free(map->map_int[j]);
				j++;
			}
			free(map->map_int);
			map->map_int = NULL;
		}
		i++;
	}
	init_map(map);
}

void	init_map(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	map->sol.x = 0;
	map->sol.y = 0;
	map->sol.value = 1;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->cols)
		{
			if ((j == 0 || i == 0)
				&& map->map[i][j] != map->obj)
				map->map_int[i][j] = 1;
			if (map->map[i][j] == map->obj)
				map->map_int[i][j] = 0;
			j++;
		}
		i++;
	}
}
