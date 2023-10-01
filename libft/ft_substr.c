/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:58:49 by mredkole          #+#    #+#             */
/*   Updated: 2023/01/25 18:30:16 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	size;

	if (!s)
		return (0);
	size = ft_strlen(&s[start]);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > size)
		len = size;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	ft_strlcpy(arr, &s[start], len + 1);
	return (arr);
}
