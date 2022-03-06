/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:08:28 by tdeville          #+#    #+#             */
/*   Updated: 2022/02/01 17:56:10 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

static void	get_line(char **line, int fd, char *buffer)
{
	int		r;
	char	*tmp;

	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		buffer[r] = '\0';
		if (!*line)
			*line = ft_substr(buffer, 0, r);
		else
		{
			tmp = *line;
			*line = ft_strjoin(*line, buffer);
			free(tmp);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
}

static char	*parse_line(char **line)
{
	int		j;
	char	*tmp;
	char	*mem;

	if (!*line)
		return (NULL);
	if (!ft_strchr(*line, '\n'))
	{
		if (*line[0] == '\0')
		{
			free(*line);
			*line = NULL;
			return (NULL);
		}
		tmp = ft_substr(*line, 0, ft_strlen(*line));
		free(*line);
		*line = NULL;
		return (tmp);
	}
	j = ft_strlen(ft_strchr(*line, '\n'));
	mem = *line;
	tmp = ft_substr(*line, 0, ft_strlen(*line) - j + 1);
	*line = ft_substr(ft_strchr(*line, '\n'), 1, j);
	free(mem);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;
	char		buffer[BUFFER_SIZE + 1];

	if (read(fd, buffer, 0) == -1 || BUFFER_SIZE < 0)
		return (NULL);
	if (!(ft_strchr(line, '\n')))
		get_line(&line, fd, buffer);
	str = parse_line(&line);
	return (str);
}
