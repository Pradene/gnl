#include "get_next_line.h"

static void	add_to_stash(char **stash, char *buf, int readc) {
	char	*s;
	int		size;

	size = (int)ft_strlen((*stash));
	s = malloc(sizeof(char) * (size + readc + 1));
	if (s == NULL)
		return ;
	if ((*stash) != NULL) {
		ft_memcpy(s, (*stash), size);
		free((*stash));
	}
	ft_memcpy(s + size, buf, readc);
	s[size + readc] = '\0';
	(*stash) = s;
}

static void	read_file(char **stash, int fd) {
	char	buf[BUFFER_SIZE + 1];
	int		readc;

	while (ft_strchr(*stash, '\n') == NULL) {
		readc = read(fd, buf, BUFFER_SIZE);
		if (readc <= 0) {
			if (readc == -1 && (*stash) != NULL) {
				free((*stash));
				(*stash) = NULL;
			}
			return ;
		}
		buf[readc] = '\0';
		add_to_stash(stash, buf, readc);
		if ((*stash) == NULL) {
			return ;
		}
	}
}

static void	make_line(char **line, char *stash) {
	int	i;

	(*line) = NULL;
	if (stash == NULL)
		return ;
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	*line = malloc(sizeof(char) * (i + 1));
	if ((*line) == NULL)
		return ;
	ft_memcpy(*line, stash, i);
	(*line)[i] = '\0';
}

static void	clean_stash(char **stash) {
	int		i;
	int		j;
	char	*s;

	if ((*stash) == NULL)
		return ;
	i = 0;
	while ((*stash)[i] != '\0' && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	s = malloc(sizeof(char) * ((int)ft_strlen((*stash)) - i + 1));
	if (s == NULL)
		return ;
	j = 0;
	while ((*stash)[i] != '\0') {
		s[j] = (*stash)[i];
		j++;
		i++;
	}
	s[j] = '\0';
	free((*stash));
	(*stash) = s;
}

char	*get_next_line(int fd) {
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file(&stash, fd);
	if (!stash)
		return (NULL);
	make_line(&line, stash);
	clean_stash(&stash);
	if (line[0] == '\0') {
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
