/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:24:05 by mredkole          #+#    #+#             */
/*   Updated: 2023/07/07 17:45:37 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_arr(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (0);
}

static int	counter_words(char const *arr, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == c)
			i++;
		else
		{
			words++;
			while (arr[i] && arr[i] != c)
				i++;
		}
	}
	return (words);
}

static char	*add_word(char *word, char const *arr, int i, int len)
{
	int	j;

	j = 0;
	while (len > 0)
	{
		word[j] = arr[i - len];
		j++;
		len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**split_words(char const *arr, char c, char **res, int words)
{
	int	i;
	int	word;
	int	len;

	i = 0;
	word = 0;
	len = 0;
	while (word < words)
	{
		while (arr[i] && arr[i] == c)
			i++;
		while (arr[i] && arr[i] != c)
		{
			i++;
			len++;
		}
		res[word] = (char *)malloc(sizeof(char) * (len + 1));
		if (!res)
			return (free_arr(res, word));
		add_word(res[word], arr, i, len);
		len = 0;
		word++;
	}
	res[word] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	words;

	if (!s)
		return (0);
	words = counter_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (0);
	res = split_words(s, c, res, words);
	return (res);
}
