/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:44:27 by itrueba-          #+#    #+#             */
/*   Updated: 2023/03/06 17:54:13 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcat_gnl(char *dst, char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	len;

	dstlen = ft_strlen_gnl(dst);
	srclen = ft_strlen_gnl(src);
	len = 0;
	if (!dstsize)
		return (srclen);
	while (src[len] && (dstlen + len) < (dstsize - 1))
	{
		dst[dstlen + len] = src[len];
		len++;
	}
	dst[dstlen + len] = '\0';
	if (dstlen > dstsize)
		return (srclen + dstsize);
	return (srclen + dstlen);
}

size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	len;

	srcsize = ft_strlen_gnl(src);
	len = 0;
	if (dstsize != 0)
	{
		while (src[len] && len < (dstsize - 1))
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	return (srcsize);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	ptr = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy_gnl(ptr, s1, ft_strlen_gnl(s1) + 1);
	ft_strlcat_gnl(ptr, s2, ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	free(s1);
	return (ptr);
}
