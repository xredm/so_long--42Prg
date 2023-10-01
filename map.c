/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:47:26 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 21:50:42 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move(t_win *me)
{
	if (((*me).map.layout[(*me).map.enemy_coor.y
				+ (*me).enmv][(*me).map.enemy_coor.x] != '1'))
	{
		(*me).map.layout[(*me).map.enemy_coor.y][(*me).map.enemy_coor.x] = '0';
		(*me).map.layout[(*me).map.enemy_coor.y
			+ (*me).enmv][(*me).map.enemy_coor.x] = 'S';
		(*me).map.enemy_coor.y += (*me).enmv;
	}
	else
		(*me).enmv *= -1;
}

void	move(t_win *m, int yc, int xc)
{
	if (((*m).map.layout[(*m).map.player_coor.y
				+ yc][(*m).map.player_coor.x + xc] != '1')
	&& ((*m).map.layout[(*m).map.player_coor.y
				+ yc][(*m).map.player_coor.x + xc] != 'E'))
	{
		if ((*m).map.layout[(*m).map.player_coor.y
				+ yc][(*m).map.player_coor.x + xc] == 'C')
			(*m).map.collectible--;
		(*m).map.layout[(*m).map.player_coor.y][(*m).map.player_coor.x] = '0';
		(*m).map.layout[(*m).map.player_coor.y
			+ yc][(*m).map.player_coor.x + xc] = 'P';
		(*m).map.player_coor.y += yc;
		(*m).map.player_coor.x += xc;
		(*m).movec++;
	}
	if ((*m).map.collectible == 0)
	{
		(*m).map.layout[(*m).map.exit_coor.y][(*m).map.exit_coor.x] = 'X';
	}
}

void	map_initialization(t_map *map)
{
	(*map).layout = NULL;
	(*map).height = 0;
	(*map).width = 0;
	(*map).collectible = 0;
	(*map).exit = 0;
	(*map).start = 0;
	(*map).player_coor.x = 0;
	(*map).player_coor.y = 0;
	(*map).exit_coor.x = 0;
	(*map).exit_coor.y = 0;
	(*map).enemy_coor.y = 0;
	(*map).enemy_coor.y = 0;
}
