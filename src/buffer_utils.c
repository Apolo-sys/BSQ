/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-go <cruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:00:00 by usuario           #+#    #+#             */
/*   Updated: 2025/03/11 23:10:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	copy_buffer(char *content, char *buffer, int buffer_size)
{
	int	i;

	i = 0;
	while (i < buffer_size)
	{
		content[i] = buffer[i];
		i++;
	}
	content[buffer_size] = '\0';
}

int	validate_and_build(t_map *map, char *content)
{
	if (!validate_map(map, content))
		return (0);
	if (!build_map_matrix(map, content))
		return (0);
	return (1);
}

int	build_from_buffer(t_map *map, char *buffer, int buffer_size)
{
	char	*content;
	int		result;

	content = malloc(buffer_size + 1);
	if (!content)
		return (0);
	copy_buffer(content, buffer, buffer_size);
	result = read_more_stdin(&content, &buffer_size);
	if (!result)
	{
		free(content);
		return (0);
	}
	result = validate_and_build(map, content);
	free(content);
	return (result);
}
