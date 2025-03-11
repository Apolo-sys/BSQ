/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-go <cruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:00:00 by usuario           #+#    #+#             */
/*   Updated: 2025/03/11 23:55:42 by cruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_first_line(char *buffer, unsigned int *l)
{
	*l = 0;
	while (buffer[*l] && buffer[*l] != '\n')
		(*l)++;
	if (buffer[*l] != '\n')
		return (0);
	return (1);
}

int	parse_params(t_map *map, char *buffer, unsigned int *l, unsigned int *i)
{
	*i = 0;
	map->lines = ft_atoi(buffer);
	while (buffer[*i] >= '0' && buffer[*i] <= '9')
		(*i)++;
	if (*i + 2 >= *l)
		return (0);
	map->empty = buffer[(*i)++];
	map->obj = buffer[(*i)++];
	map->full = buffer[*i];
	return (1);
}

unsigned int	readparams_stdin(t_map *map)
{
	char			buffer[4096];
	unsigned int	i;
	unsigned int	l;
	int				read_size;
	int				has_more;

	read_size = read(STDIN_FILENO, buffer, 4095);
	if (read_size <= 0)
		return (0);
	buffer[read_size] = '\0';
	if (!check_first_line(buffer, &l))
		return (0);
	if (!parse_params(map, buffer, &l, &i))
		return (0);
	has_more = (l + 1 < (unsigned int)read_size);
	if (has_more)
		if (!build_from_buffer(map, buffer + l + 1, read_size - l - 1))
			return (0);
	return (l);
}

unsigned int	readparams(t_map *map, int fd, char *file)
{
	unsigned int	l;
	int				i;
	char			b[2];
	char			*fline;

	l = 0;
	while (read(fd, b, 1) == 1 && *b != '\n')
		l++;
	close(fd);
	fd = open(file, O_RDONLY);
	fline = (char *)malloc(l + 1);
	i = 0;
	read(fd, fline, l);
	fline[l] = 0;
	map->lines = ft_atoi(fline);
	while (fline[i] >= '0' && fline[i] <= '9')
		i++;
	map->empty = fline[i++];
	map->obj = fline[i++];
	map->full = fline[i];
	free(fline);
	close(fd);
	return (l);
}
