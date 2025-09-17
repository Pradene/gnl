#include "get_next_line.h"

size_t	ft_strlen(const char *s) {
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c) {
	int	i;
	int size;

	if (s == NULL) {
		return (NULL);
	}
	i = 0;
	size = (int)ft_strlen(s);
	while (i <= size) {
		if (s[i] == (char)c) {
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n) {
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memset(void *s, int value, size_t n) {
	size_t	i;

	i = 0;
	while (i < n) {
		((char *)s)[i++] = value;
	}
	return (s);
}