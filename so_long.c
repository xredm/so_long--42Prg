/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:02:15 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 21:50:14 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keysym, t_win *me)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(me->mlx_ptr, me->win_ptr);
		mlx_destroy_display(me->mlx_ptr);
		free_stuff(me);
		exit(0);
	}
	else if (keysym == XK_w && me->flag)
		move(me, -1, 0);
	else if (keysym == XK_a && me->flag)
		move(me, 0, -1);
	else if (keysym == XK_d && me->flag)
		move(me, 0, 1);
	else if (keysym == XK_s && me->flag)
		move(me, 1, 0);
	ft_printf("Number of moves: %d\n", me->movec);
	return (0);
}

int	exit_prg(t_win *me)
{
	if (me)
	{
		mlx_destroy_window(me->mlx_ptr, me->win_ptr);
		mlx_destroy_display(me->mlx_ptr);
		free_stuff(me);
	}
	exit(0);
}

int	main(int ac, char **av)
{
	t_win	me;

	check_args(ac, av, &me);
	me.map = assign_map(me.mapargv);
	me.h = (me.map.height) * 40;
	me.w = (me.map.width - 1) * 40;
	me.mlx_ptr = mlx_init();
	me.win_ptr = mlx_new_window(me.mlx_ptr, me.w, me.h, "game");
	me.rng = 0;
	me.flag = 1;
	me.enmv = 1;
	me.movec = 0;
	sprites_init(&me);
	mlx_loop_hook(me.mlx_ptr, next_frame, &me);
	mlx_hook(me.win_ptr, 2, 1L << 2, handle_key, &me);
	mlx_hook(me.win_ptr, 17, 1L << 0, exit_prg, &me);
	mlx_loop(me.mlx_ptr);
}
