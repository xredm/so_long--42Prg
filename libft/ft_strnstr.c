/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:33:45 by mredkole          #+#    #+#             */
/*   Updated: 2023/01/25 14:45:21 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len == 0 && big == NULL)
		return (0);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && big[i + j] != '\0' && (i + j) < len)
		{
			j++;
		}
		if (j == ft_strlen(little))
		{
			return ((char *)&big[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
