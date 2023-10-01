/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:45:27 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/04 15:40:27 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	counter_char(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*fill_arr(unsigned int n, char *arr, long int len)
{
	while (n > 0)
	{
		arr[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char			*arr;
	long int		len;
	unsigned int	nb;

	len = counter_char(n);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	if (n == 0)
		arr[0] = '0';
	if (n < 0)
	{
		arr[0] = '-';
		nb = (unsigned int)n * (-1);
	}
	else
		nb = (unsigned int)n;
	arr[len--] = '\0';
	fill_arr(nb, arr, len);
	return (arr);
}
