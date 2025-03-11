/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:10:23 by jaicastr          #+#    #+#             */
/*   Updated: 2025/03/11 23:10:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	parse_and_build_map(t_map *map, char *file, unsigned int offset)
{
	char	*content;

	content = read_map_content(file, offset);
	if (!content)
		return (0);
	if (!validate_map(map, content))
	{
		free(content);
		return (0);
	}
	if (!build_map_matrix(map, content))
	{
		free(content);
		return (0);
	}
	free(content);
	return (1);
}
