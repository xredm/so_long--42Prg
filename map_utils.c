/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:24:49 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 21:54:18 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood(t_map *map, int y, int x)
{
	if ((*map).layouttest[y][x] == '1' || (*map).layouttest[y][x] == 'F')
		return (0);
	if ((*map).layouttest[y][x] == 'C')
	{
		(*map).coltest -= 1;
	}
	if ((*map).layouttest[y][x] == 'E')
	{
		(*map).extest -= 1;
	}
	if ((*map).layouttest[y][x] == 'E')
	{
		(*map).layouttest[y][x] = '1';
		return (0);
	}
	else
		(*map).layouttest[y][x] = 'F';
	flood(map, y + 1, x);
	flood(map, y - 1, x);
	flood(map, y, x - 1);
	flood(map, y, x + 1);
	return (1);
}

int	check_path(t_map map)
{
	map.coltest = map.collectible;
	map.extest = map.exit;
	flood(&map, map.player_coor.y, map.player_coor.x);
	if (map.extest != 0 || map.coltest != 0)
	{
		return (0);
	}
	return (1);
}

//'S' is for the enemy
void	check_lines(char **layout, t_map *map, int h, int w)
{
	if (h == 0 || h == (*map).height - 1 || w == 0 || w == (*map).width - 1)
	{
		if (layout[h][w] != '1')
			error_msg(2);
	}
	else if (layout[h][w] == 'E')
		exit_coordinates(map, h, w);
	else if (layout[h][w] == 'P')
	{
		(*map).start++;
		(*map).player_coor.x = w;
		(*map).player_coor.y = h;
	}
	else if (layout[h][w] == 'S')
	{
		(*map).enemy_coor.x = w;
		(*map).enemy_coor.y = h;
	}
	else if (layout[h][w] == 'C')
	{
		(*map).collectible++;
	}
	else if (layout[h][w] != '0' && layout[h][w] != '1')
		error_msg(5);
}

void	check_map_reqs(char **layout, t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (layout[h])
	{
		w = 0;
		if (ft_strlen(layout[0]) != ft_strlen(layout[h]))
			error_msg(1);
		while (layout[h][w])
		{
			check_lines(layout, map, h, w);
			w++;
		}
		h++;
	}
	if ((*map).exit != 1 || (*map).start != 1 || (*map).collectible < 1)
		error_msg(3);
	if (!check_path(*map))
		error_msg(4);
}

t_map	assign_map(char *map)
{
	t_map		res_map;
	int			fd;
	char		*layout;
	char		*line;

	fd = open(map, O_RDONLY);
	layout = ft_strdup("");
	line = get_next_line(fd);
	map_initialization(&res_map);
	while (line != NULL)
	{
		layout = ft_strjoin(layout, line);
		free(line);
		line = get_next_line(fd);
		res_map.height++;
	}
	res_map.layout = ft_split(layout, '\n');
	res_map.layouttest = ft_split(layout, '\n');
	if (res_map.layout[0])
		res_map.width = ft_strlen(res_map.layout[0]);
	check_map_reqs(res_map.layout, &res_map);
	free_chars(&layout, &line);
	close(fd);
	return (res_map);
}
