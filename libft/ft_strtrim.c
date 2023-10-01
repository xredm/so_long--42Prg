/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:50:01 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/04 15:49:45 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_array(char const *set, char a)
{
	int	x;

	x = 0;
	while (set[x] != '\0')
	{
		if (set[x] == a)
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*arr;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	if (!set || !s1)
		return (0);
	while (check_array(set, s1[i]))
		i++;
	while (check_array(set, s1[j - 1]) && j > i)
		j--;
	arr = malloc(sizeof(char) * (j - i + 1));
	if (!arr)
		return (0);
	while (i < j)
		arr[k++] = s1[i++];
	arr[k] = '\0';
	return (arr);
}
