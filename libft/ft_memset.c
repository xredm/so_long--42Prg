/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:13:00 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 21:43:57 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = s;
	while (i < n)
	{
		arr[i] = c;
		i++;
	}
	return (s);
}
