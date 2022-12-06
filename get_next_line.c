/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:43 by lpradene          #+#    #+#             */
/*   Updated: 2022/11/30 23:47:00 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_buf(&stash, fd);
	if (!stash)
		return (0);
	make_line(&line, stash);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free(stash);
		stash = 0;
		free(line);
		return (0);
	}
	return (line);
}

void	read_buf(char **stash, int fd)
{
	char	*buf;
	int		readc;

	readc = 1;
	while (!search_newline(*stash) && readc != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		readc = read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readc == -1) || readc == 0)
		{
			free(buf);
			return ;
		}
		buf[readc] = '\0';
		add_to_stash(stash, buf, readc);
		free(buf);
	}
}

void	add_to_stash(char **stash, char *buf, int readc)
{
	char	*s;

	s = malloc(sizeof(char) * (ft_strlen(*stash) + readc + 1));
	if (!s)
		return ;
	ft_memcpy(s, *stash, ft_strlen(*stash));
	ft_memcpy(s + ft_strlen(*stash), buf, readc + 1);
	free(*stash);
	*stash = s;
}

void	make_line(char **line, char *stash)
{
	int	i;

	if (!stash)
		return ;
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	*line = malloc(sizeof(char) * (i + 1));
	if (!(*line))
		return ;
	ft_memcpy(*line, stash, i);
	(*line)[i] = '\0';
}

void	clean_stash(char **stash)
{
	int		i;
	int		j;
	char	*s;

	if (!(*stash))
		return ;
	i = 0;
	while ((*stash)[i] != '\n' && (*stash)[i])
		i++;
	if ((*stash)[i] == '\n')
		i++;
	s = malloc(sizeof(char) * (ft_strlen(*stash) - i + 1));
	if (!s)
		return ;
	j = 0;
	while ((*stash)[i])
	{
		s[j] = (*stash)[i];
		j++;
		i++;
	}
	s[j] = '\0';
	free(*stash);
	*stash = s;
}
