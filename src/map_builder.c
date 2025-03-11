/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:10:21 by jaicastr          #+#    #+#             */
/*   Updated: 2025/03/11 23:10:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	validate_map(t_map *map, char *content)
{
	unsigned int	line_len;

	line_len = get_line_len(content);
	if (line_len == 0)
		return (0);
	if (!validate_chars(map, content))
		return (0);
	if (!validate_lines(map, content, line_len))
		return (0);
	map->cols = line_len;
	return (1);
}

int	alloc_map_matrix(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	map->map = (char **)malloc(sizeof(char *) * map->lines);
	if (!map->map)
		return (0);
	i = 0;
	while (i < map->lines)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->cols + 1));
		if (!map->map[i])
		{
			j = 0;
			while (j < i)
			{
				free(map->map[j]);
				j++;
			}
			free(map->map);
			map->map = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

void	fill_map_matrix(t_map *map, char *content)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (content[i] && k < map->lines)
	{
		j = 0;
		while (content[i] && content[i] != '\n' && j < map->cols)
		{
			map->map[k][j] = content[i];
			i++;
			j++;
		}
		map->map[k][j] = '\0';
		if (content[i])
			i++;
		k++;
	}
}

int	build_map_matrix(t_map *map, char *content)
{
	if (!alloc_map_matrix(map))
		return (0);
	fill_map_matrix(map, content);
	return (1);
}
