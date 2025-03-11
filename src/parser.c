/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:10:25 by jaicastr          #+#    #+#             */
/*   Updated: 2025/03/11 23:10:41 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_map_content(char *file, unsigned int param_line_len)
{
	unsigned int	read_bytes;
	unsigned int	len;
	int				fd;
	char			*content;
	char			buffer[1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	len = 0;
	while (read(fd, buffer, 1) > 0)
		len++;
	close(fd);
	fd = open(file, O_RDONLY);
	read_bytes = 0;
	while (read_bytes < param_line_len + 1 && read(fd, buffer, 1) > 0)
		read_bytes++;
	content = malloc(sizeof(char) * (len - param_line_len));
	read_bytes = read(fd, content, len - param_line_len - 1);
	content[read_bytes] = '\0';
	close(fd);
	return (content);
}

char	*read_content(int fd, char *content, unsigned int size)
{
	if (read(fd, content, size) <= 0)
	{
		free(content);
		close(fd);
		return (NULL);
	}
	content[size] = '\0';
	close(fd);
	return (content);
}

unsigned int	get_line_len(char *content)
{
	unsigned int	len;

	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	return (len);
}

int	validate_chars(t_map *map, char *content)
{
	unsigned int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != '\n' && content[i] != map->empty
			&& content[i] != map->obj)
			return (0);
		i++;
	}
	return (1);
}

int	validate_lines(t_map *map, char *content, unsigned int line_len)
{
	unsigned int	i;
	unsigned int	count;
	unsigned int	lines;

	i = 0;
	count = 0;
	lines = 0;
	while (content[i])
	{
		if (content[i] == '\n')
		{
			if (count != line_len)
				return (0);
			count = 0;
			lines++;
		}
		else
			count++;
		i++;
	}
	if (count != 0 && count != line_len)
		return (0);
	if (lines != map->lines)
		return (0);
	return (1);
}
