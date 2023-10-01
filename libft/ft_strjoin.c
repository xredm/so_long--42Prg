/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <mredkole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:48:28 by mredkole          #+#    #+#             */
/*   Updated: 2023/09/30 21:43:42 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	arr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
		return (0);
	while (s1[j] != '\0')
	{
		arr[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		arr[i++] = s2[j++];
	}
	arr[i] = '\0';
	return (arr);
}
