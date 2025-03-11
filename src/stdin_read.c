/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-go <cruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:00:00 by usuario           #+#    #+#             */
/*   Updated: 2025/03/11 23:10:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	copy_data(char *new_content, char *old_content,
					char *chunk, int old_size)
{
	int	i;
	int	j;
	int	chunk_size;

	chunk_size = 0;
	while (chunk[chunk_size])
		chunk_size++;
	i = 0;
	while (i < old_size)
	{
		new_content[i] = old_content[i];
		i++;
	}
	j = 0;
	while (j < chunk_size)
	{
		new_content[i + j] = chunk[j];
		j++;
	}
	new_content[i + j] = '\0';
	return (1);
}

static int	append_chunk(char **content, char *chunk, int *buffer_size)
{
	char	*new_content;
	int		chunk_size;
	int		i;

	chunk_size = 0;
	while (chunk[chunk_size])
		chunk_size++;
	new_content = malloc(*buffer_size + chunk_size + 1);
	if (!new_content)
	{
		free(*content);
		return (0);
	}
	i = copy_data(new_content, *content, chunk, *buffer_size);
	free(*content);
	*content = new_content;
	*buffer_size += chunk_size;
	return (i);
}

int	read_more_stdin(char **content, int *buffer_size)
{
	char	chunk[4096];
	int		read_size;
	int		result;

	read_size = read(STDIN_FILENO, chunk, 4095);
	while (read_size > 0)
	{
		chunk[read_size] = '\0';
		result = append_chunk(content, chunk, buffer_size);
		if (!result)
			return (0);
		read_size = read(STDIN_FILENO, chunk, 4095);
	}
	return (1);
}
