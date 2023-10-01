/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:13:55 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/02 13:33:14 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*arr;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (0);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	if (arr && f)
	{
		while (i < len)
		{
			arr[i] = (*f)(i, s[i]);
			i++;
		}
	}
	arr[i] = '\0';
	return (arr);
}
