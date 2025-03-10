// #include "bsq.h"

// void	process_buffer(char *buf)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	line = buf;
// 	while (buf[i])
// 	{
// 		if (buf[i] == '\n')
// 		{
// 			buf[i] = '\0';
// 			if (line[0] != '\0')
// 				parse_line(line);
// 			line = &buf[i + 1];
// 		}
// 		i++;
// 	}
// 	if (line[0] != '\0')
// 		parse_line(line);
// }

// void	parse_line(char *line)
// {
// 	int				i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		write(1, &line[i], 1);
// 		i++;
// 	}
// 	write(1, "\n",1);
// }

// t_map	genmap(int argc, char **argv)
// {
// 	t_map	map;
// 	char	*file_content;

// 	map.map = NULL;

// 	fill_map_matrix(file_content, &map);

// 	free(file_content);
// 	return (map);
// }

// void	*parse_map(char *filename)
// {
// 	int		fd;
// 	char	buf[4096];
// 	int		bytes;

// 	fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 		return (NULL);
// 	bytes = read(fd, buf, 4095);
// 	if (bytes <= 0)
// 	{
// 		close(fd);
// 		return (NULL);
// 	}
// 	buf[bytes] = '\0';
// 	close(fd);
// 	process_buffer(buf);
// 	return (NULL);
// }
