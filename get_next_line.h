/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:03:33 by lpradene          #+#    #+#             */
/*   Updated: 2022/11/18 17:05:34 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	read_buf(char **stash, int fd);
void	add_to_stash(char **stash, char *buf, int readc);
void	make_line(char **line, char *stash);
void	clean_stash(char **stash);

int		ft_strlen(char *s);
int		search_newline(char *stash);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif 
