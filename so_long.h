/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:30:42 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 21:57:13 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <string.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "./libft/libft.h"

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_spr
{
	void	*ptr;
	int		h;
	int		w;
}	t_spr;

typedef struct s_map
{
	t_coor	player_coor;
	t_coor	exit_coor;
	t_coor	enemy_coor;
	char	**layout;
	char	**layouttest;
	int		height;
	int		width;
	int		collectible;
	int		exit;
	int		start;
	int		coltest;
	int		extest;
}	t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		h;
	int		w;
	int		rng;
	int		enmv;
	int		movec;
	int		eudald;
	char	*mapargv;
	int		flag;
	t_map	map;
	t_spr	wall;
	t_spr	floor;
	t_spr	player;
	t_spr	player2;
	t_spr	col;
	t_spr	col2;
	t_spr	ex;
	t_spr	open;
	t_spr	en;
	t_spr	en2;
}		t_win;

void	check_args(int ac, char **av, t_win *me);
void	eudald_check(char *str, t_win *me);
int		file_check(char *map);
t_map	assign_map(char *map);
void	map_initialization(t_map *map);
void	check_map_reqs(char **layout, t_map *map);
void	error_msg(int num);
void	check_lines(char **layout, t_map *map, int i, int k);
void	exit_coordinates(t_map *map, int h, int w);
void	free_imgs(t_win *me);
void	free_stuff(t_win *me);
void	free_chars(char **layout, char **line);
int		check_path(t_map map);
int		flood(t_map *map, int y, int x);
void	sprites_init(t_win *me);
void	eudald_yes_no(t_win *me);
int		next_frame(t_win *me);
void	tiles(t_win *me);
void	next_frame_extra(t_win *me);
int		handle_key(int keysym, t_win *me);
int		exit_prg(t_win *me);
void	show_img(t_win *me, char idf, int i, int j);
void	show_img2(t_win *me, char idf);
void	enemy_move(t_win *me);
void	move(t_win *me, int yc, int xc);

#endif