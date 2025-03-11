/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-go <cruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:10:31 by jaicastr          #+#    #+#             */
/*   Updated: 2025/03/11 23:49:32 by cruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	get_position_value(size_t a, size_t b, size_t c)
{
	unsigned int	arr[3];
	unsigned int	i;
	unsigned int	min;

	i = 0;
	min = -1;
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	while (i < 3)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

void	printsol(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->cols)
		{
			if ((i >= map->sol.x - map->sol.value + 1)
				&& (i <= map->sol.x)
				&& (j >= map->sol.y - map->sol.value + 1)
				&& (j <= map->sol.y)
				&& map->map[i][j] != map->obj)
				write(1, &map->full, 1);
			else
				write(1, &map->map[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	updatesol(t_map *map, unsigned int x,
						unsigned int y)
{
	map->sol.x = x;
	map->sol.y = y;
	map->sol.value = map->map_int[x][y];
}

void	solve(t_map *map)
{
	unsigned int		i;
	unsigned int		j;

	i = 1;
	while (i < map->lines)
	{
		j = 1;
		while (j < map->cols)
		{
			if (map->map[i][j] == map->empty)
			{
				map->map_int[i][j] = get_position_value(
						map->map_int[i - 1][j],
						map->map_int[i][j - 1],
						map->map_int[i - 1][j - 1]
						) + 1;
				if (map->map_int[i][j] > map->sol.value)
					updatesol(map, i, j);
			}
			j++;
		}
		i++;
	}
}
