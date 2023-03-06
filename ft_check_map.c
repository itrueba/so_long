/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:25:45 by itrueba-          #+#    #+#             */
/*   Updated: 2023/03/06 20:54:29 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_long.h"

size_t	ft_map_lines(char *map_name, t_map *map)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening file.", map);
	len = 0;

	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		free(line);
		len++;
	}
	free(line);
	close(fd);
	return (len);
}

void	ft_all_wall(char *line, t_map *map)
{
	while (*line && *line != '\n')
	{
		if (*line != '1')
		{
			free(line);
			ft_error("No walls around the edges.", map);
		}
		line++;
	}
}

void	ft_map_element(char *line, t_map *map)
{
	while (*line && *line != '\n')
	{
		if (*line == 'C')
			map->c++;
		else if (*line == 'E')
			map->e++;
		else if (*line == 'P')
			map->p++;
		else if (*line != '0' && *line != '1')
			ft_error("Element not allowed.", map);
		line++;
	}
}

void	ft_map_gap(char *map_name, t_map *map)
{
	int		fd;
	size_t	count;
	char	*line;

	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (count < map->line)
	{
		line = get_next_line(fd);
		if (count == 0)
		{
			map->line_long = ft_strlen(line);
			ft_all_wall(line, map);
		}
		else if (count + 1 == map->line)
		{
			ft_all_wall(line, map);
			if (ft_strlen(line) + 1 != map->line_long)
			{
				free(line);
				ft_error("Different length lines.", map);
			}
		}
		else
		{
			if (line[0] != '1' || line[map->line_long - 2] != '1')
			{
				free(line);
				ft_error("No walls around the edges.", map);
			}
			ft_map_element(line, map);
			if (ft_strlen(line) != map->line_long)
			{
				free(line);
				ft_error("Different length lines.", map);
			}
		}
		free(line);
		count++;
	}
	close(fd);
}

void	ft_check_map(char *map_name)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	map->line = ft_map_lines(map_name, map);
	map->c = 0;
	map->e = 0;
	map->p = 0;
	ft_map_gap(map_name, map);
	if (map->c == 0)
		ft_error("Zero collectibles.", map);
	if (map->e != 1)
		ft_error("Only one exit allowed.", map);
	if (map->p != 1)
		ft_error("Only one starting position allowed.", map);
	free(map);
}