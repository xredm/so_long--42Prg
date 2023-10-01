/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xredm <xredm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:02:58 by mredkole          #+#    #+#             */
/*   Updated: 2023/05/11 15:19:04 by xredm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*here we join both and free the result*/
char	*ft_free(char *result, char *buffer)
{
	char	*arr;

	arr = ft_strjoin(result, buffer);
	free(result);
	return (arr);
}

char	*read_file(int fd, char *result)
{
	char	*buffer;
	int		bytes;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[bytes] = '\0';
		result = ft_free(result, buffer);
	}
	free(buffer);
	return (result);
}

/*takes one line for a return*/
char	*get_line(char *total)
{
	char	*line;
	int		i;

	i = 0;
	if (!total[i])
		return (0);
	while (total[i] && total[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (total[i] && total[i] != '\n')
	{
		line[i] = total[i];
		i++;
	}
	if (total[i] == '\n')
		line[i++] = '\n';
	return (line);
}

/*delete prev line and get next*/
char	*next_line(char *total)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (total[i] && total[i] != '\n')
		i++;
	if (!total[i])
	{
		free(total);
		return (0);
	}
	line = ft_calloc((ft_strlen(total) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (total[i])
		line[j++] = total[i++];
	free(total);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*total;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	total = read_file(fd, total);
	if (!total)
		return (0);
	line = get_line(total);
	total = next_line(total);
	return (line);
}
