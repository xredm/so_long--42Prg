/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:33:00 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 22:08:36 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_chars(char **layout, char **line)
{
	free(*layout);
	free(*line);
}

void	free_imgs(t_win *me)
{
	free(me->wall.ptr);
	free(me->player.ptr);
	free(me->player2.ptr);
	free(me->floor.ptr);
	free(me->open.ptr);
	free(me->ex.ptr);
	free(me->col.ptr);
	free(me->col2.ptr);
	free(me->en.ptr);
	free(me->en2.ptr);
}

void	free_stuff(t_win *me)
{
	int	i;

	i = 0;
	free(me->mlx_ptr);
	while (me->map.layout[i])
	{
		free(me->map.layout[i]);
		free(me->map.layouttest[i]);
		i++;
	}
	free(me->map.layout[i]);
	free(me->map.layouttest[i]);
	free(me->map.layout);
	free(me->map.layouttest);
	free_imgs(me);
}

void	exit_coordinates(t_map *map, int h, int w)
{
	(*map).exit++;
	(*map).exit_coor.x = w;
	(*map).exit_coor.y = h;
}

void	error_msg(int num)
{
	if (num == 1)
		ft_printf("ERROR\nMAP IS NOT RECTANGULAR\n");
	else if (num == 2)
		ft_printf("ERROR\nMAP IS NOT SURROUNDED BY WALLS\n");
	else if (num == 3)
		ft_printf("ERROR\nMAP CONTAINS INVALID NUMBER OF GAME OBJECTS\n");
	else if (num == 4)
		ft_printf("ERROR\nMAP DOESN'T CONTAIN VALID PATH\n");
	else if (num == 5)
		ft_printf("ERROR\nINVALID SYMBOL XD\n");
	exit (0);
}
