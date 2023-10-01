/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:19:33 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 22:06:43 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_img2(t_win *me, char idf)
{
	if (idf == 'P' && me->rng > 5000)
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->player.ptr,
			(me->w / me->map.width) * me->map.player_coor.x,
			(me->h / me->map.height) * me->map.player_coor.y);
	else if (idf == 'P')
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->player2.ptr,
			(me->w / me->map.width) * me->map.player_coor.x,
			(me->h / me->map.height) * me->map.player_coor.y);
	else if (idf == 'S' && me->rng > 50000)
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->en.ptr,
			(me->w / me->map.width) * me->map.enemy_coor.x,
			(me->h / me->map.height) * me->map.enemy_coor.y);
	else if (idf == 'S')
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr,
			me->en2.ptr, (me->w / me->map.width) * me->map.enemy_coor.x,
			(me->h / me->map.height) * me->map.enemy_coor.y);
}

void	show_img(t_win *me, char idf, int i, int j)
{
	if (idf == 'C' && me->rng > 5000)
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->col.ptr,
			(me->w / me->map.width) * j, (me->h / me->map.height) * i);
	else if (idf == 'C')
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->col2.ptr,
			(me->w / me->map.width) * j, (me->h / me->map.height) * i);
	else if (idf == '1')
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->wall.ptr,
			(me->w / me->map.width) * j, (me->h / me->map.height) * i);
	else if (idf == '0')
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->floor.ptr,
			(me->w / me->map.width) * j, (me->h / me->map.height) * i);
	else if (idf == 'E')
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->ex.ptr,
			(me->w / me->map.width) * j, (me->h / me->map.height) * i);
	else if (idf == 'X')
		mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->open.ptr,
			(me->w / me->map.width) * j, (me->h / me->map.height) * i);
	show_img2(me, idf);
}

void	next_frame_extra(t_win *me)
{
	if (me->rng % 20000 == 0)
		enemy_move(me);
	me->rng++;
	if (me->rng > 100000)
		me->rng = 0;
	if (me->map.player_coor.x == me->map.enemy_coor.x
		&& me->map.player_coor.y == me->map.enemy_coor.y)
	{
		me->map = assign_map(me->mapargv);
		me->movec = 0;
	}
}

void	eudald_yes_no(t_win *me)
{
	if (me->eudald == 1)
	{
		me->player.ptr = mlx_xpm_file_to_image(me->mlx_ptr,
				"./sprites/dog.xpm", &(me->player.w), &(me->player.h));
		me->player2.ptr = mlx_xpm_file_to_image(me->mlx_ptr,
				"./sprites/dog.xpm", &(me->player.w), &(me->player.h));
	}
	else
	{
		me->player.ptr = mlx_xpm_file_to_image(me->mlx_ptr,
				"./sprites/player.xpm",
				&(me->player.w), &(me->player.h));
		me->player2.ptr = mlx_xpm_file_to_image(me->mlx_ptr,
				"./sprites/player2.xpm", &(me->player2.w), &(me->player2.h));
	}
}

void	sprites_init(t_win *me)
{
	me->wall.ptr = mlx_xpm_file_to_image(me->mlx_ptr, "./sprites/wall.xpm",
			&(me->wall.w), &(me->wall.h));
	eudald_yes_no(me);
	me->floor.ptr = mlx_xpm_file_to_image(me->mlx_ptr, "./sprites/floor.xpm",
			&(me->floor.w), &(me->floor.h));
	me->ex.ptr = mlx_xpm_file_to_image(me->mlx_ptr, "./sprites/exit.xpm",
			&(me->ex.w), &(me->ex.h));
	me->open.ptr = mlx_xpm_file_to_image(me->mlx_ptr, "./sprites/open.xpm",
			&(me->open.w), &(me->open.h));
	me->col.ptr = mlx_xpm_file_to_image(me->mlx_ptr,
			"./sprites/collectible.xpm",
			&(me->col.w), &(me->col.h));
	me->col2.ptr = mlx_xpm_file_to_image(me->mlx_ptr,
			"./sprites/collectible2.xpm",
			&(me->col2.w), &(me->col2.h));
	me->en.ptr = mlx_xpm_file_to_image(me->mlx_ptr, "./sprites/enemy.xpm",
			&(me->en.w), &(me->en.h));
	me->en2.ptr = mlx_xpm_file_to_image(me->mlx_ptr, "./sprites/enemy1.xpm",
			&(me->en2.w), &(me->en2.h));
}
