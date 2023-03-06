/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:16:45 by itrueba-          #+#    #+#             */
/*   Updated: 2022/12/03 13:08:02 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	len;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
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
