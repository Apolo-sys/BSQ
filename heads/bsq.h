/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:32:58 by jaicastr          #+#    #+#             */
/*   Updated: 2025/03/11 23:33:01 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct map_vars
{
	int				fd;
	unsigned int	len;
	unsigned int	read_bytes;
	char			*content;
	char			buffer[1];
}	t_map_vars;

typedef struct s_sol
{
	unsigned int		x;
	unsigned int		y;
	int					value;
}	t_sol;

typedef struct s_map
{
	char			**map;
	int				**map_int;
	unsigned int	lines;
	unsigned int	cols;
	char			empty;
	char			obj;
	char			full;
	t_sol			sol;
}	t_map;

int				process_map_file(char *file);
int				process_map_stdin(void);
void			free_map(t_map *map);
void			debuglol(t_map *map);
unsigned int	readparams(t_map *map, int fd, char *file);
char			*read_map_content(char *file, unsigned int offset);
char			*read_content(int fd, char *content, unsigned int size);
int				parse_and_build_map(t_map *map, char *file,
					unsigned int offset);
unsigned int	readparams_stdin(t_map *map);
int				check_first_line(char *buffer, unsigned int *l);
int				parse_params(t_map *map, char *buffer, unsigned int *l,
					unsigned int *i);
int				build_from_buffer(t_map *map, char *buffer, int buffer_size);
void			copy_buffer(char *content, char *buffer, int buffer_size);
int				validate_and_build(t_map *map, char *content);
int				read_more_stdin(char **content, int *buffer_size);
unsigned int	get_line_len(char *content);
int				validate_chars(t_map *map, char *content);
int				validate_lines(t_map *map, char *content,
					unsigned int line_len);
int				validate_map(t_map *map, char *content);
int				alloc_map_matrix(t_map *map);
void			fill_map_matrix(t_map *map, char *content);
int				build_map_matrix(t_map *map, char *content);
void			init_map(t_map *map);
void			alloc_sol_map(t_map *map);
void			free_sol_map(t_map *map);
void			solve(t_map *map);
void			printsol(t_map *map);
int				ft_atoi(char *str);

#endif