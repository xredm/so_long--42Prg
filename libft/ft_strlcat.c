/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:46:23 by mredkole          #+#    #+#             */
/*   Updated: 2023/01/23 16:32:27 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	if (!dest && size == 0)
		return (src_len);
	while (dest[i] && i < size)
		i++;
	if (size > 0)
	{
		while (src[j] && i + 1 < size)
		{
			dest[i++] = src[j++];
		}
	}
	if (j > 0)
	{
		dest[i] = '\0';
		return (src_len + i - j);
	}
	return (src_len + i);
}
