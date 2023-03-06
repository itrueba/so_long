/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:02:08 by itrueba-          #+#    #+#             */
/*   Updated: 2023/03/06 20:44:27 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# define BUFFER_SIZE 1000000

char	*ft_leftovers(char *leftovers)
{
	int		len;
	char	*new_leftovers;

	len = 0;
	while (leftovers[len] && leftovers[len] != '\n')
		len++;
	if (!leftovers[len])
	{
		free(leftovers);
		return (NULL);
	}
	new_leftovers = malloc(ft_strlen_gnl(leftovers) - len);
	if (!new_leftovers)
		return (NULL);
	len++;
	ft_strlcpy_gnl(new_leftovers, &leftovers[len], ft_strlen_gnl(leftovers) - len + 1);
	free(leftovers);
	return (new_leftovers);
}

char	*ft_line(char *leftovers)
{
	char	*new_line;
	int		len;

	if (!leftovers[0])
		return (NULL);
	len = 1;
	while (leftovers[len] && leftovers[len - 1] != '\n')
		len++;
	new_line = malloc(len + 1);
	if (!new_line)
		return (NULL);
	ft_strlcpy_gnl(new_line, leftovers, len + 1);
	return (new_line);
}

char	*ft_strchr_gnl(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft_read(int fd, char *leftovers)
{
	char	*buffer;
	int		number_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	number_bytes = 1;
	while (!ft_strchr_gnl(leftovers, '\n') && number_bytes != 0)
	{
		number_bytes = read(fd, buffer, BUFFER_SIZE);
		if (number_bytes == -1)
		{
			free(leftovers);
			free(buffer);
			return (NULL);
		}
		buffer[number_bytes] = '\0';
		leftovers = ft_strjoin_gnl(leftovers, buffer);
	}
	free(buffer);
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftovers = ft_read(fd, leftovers);
	if (!leftovers)
		return (NULL);
	line = ft_line(leftovers);
	leftovers = ft_leftovers(leftovers);
	free (leftovers);
	return (line);
}
