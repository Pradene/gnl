#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	read_file(char **stash, int fd);
void	add_to_stash(char **stash, char *buf, int readc);
void	make_line(char **line, char *stash);
void	clean_stash(char **stash);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *string, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int value, size_t n);

#endif 
