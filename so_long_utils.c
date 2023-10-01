/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:32:38 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 22:05:17 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tiles(t_win *me)
{
	int	i;
	int	j;

	i = 0;
	while (me->map.layout[i])
	{
		j = 0;
		while (me->map.layout[i][j])
		{
			show_img(me, me->map.layout[i][j], i, j);
			j++;
		}
		i++;
	}
}

int	next_frame(t_win *me)
{
	char	*moves;

	moves = ft_itoa(me->movec);
	if (me->rng % 100 == 0)
	{
		mlx_clear_window(me->mlx_ptr, me->win_ptr);
		tiles(me);
		mlx_string_put(me->mlx_ptr, me->win_ptr, 20, 20, 1111111,
			moves);
	}
	free(moves);
	next_frame_extra(me);
	if (me->map.player_coor.x == me->map.exit_coor.x
		&& me->map.player_coor.y == me->map.exit_coor.y)
	{
		mlx_string_put(me->mlx_ptr, me->win_ptr, me->w / 2, me->h / 2,
			1111111, "Damn, you made it 0_0");
		me->flag = 0;
	}
	return (1);
}

int	file_check(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] == 'r')
	{
		if (map[len - 2] == 'e')
		{
			if (map[len - 3] == 'b')
			{
				if (map[len - 4] == '.')
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

//checks if second argument is same as intended for a change of character
void	eudald_check(char *str, t_win *me)
{
	char	*name;
	int		i;

	name = "eudald";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == name[i])
			i++;
		else
			me->eudald = 0;
	}
	me->eudald = 1;
}

//if ac > 2 it ll check second argument string if its == 'eudald' and if yes 
//change our character to eudald
//then will check if map is good and ll assign it
void	check_args(int ac, char **av, t_win *me)
{
	me->eudald = 0;
	if (ac > 2)
	{
		ft_printf("Only the first argument will be taken into consideration\n");
		eudald_check(av[2], me);
	}
	if (ac == 1)
	{
		ft_printf("You forgot to add a map file\n");
		exit(0);
	}
	if (file_check(av[1]) == 0)
	{
		ft_printf("The format of the file is not correct\n");
		exit(0);
	}
	me->mapargv = av[1];
}
