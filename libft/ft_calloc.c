/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:33:46 by mredkole          #+#    #+#             */
/*   Updated: 2023/01/25 16:56:03 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	arr = (void *)malloc(nmemb * size);
	if (nmemb == 0 || size == 0)
	{
		arr = malloc(0);
		return (arr);
	}
	if (((nmemb * size) / nmemb) != size)
		return (0);
	if (!arr)
		return (0);
	ft_bzero(arr, (nmemb * size));
	return (arr);
}
