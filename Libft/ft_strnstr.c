/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:51:31 by itrueba-          #+#    #+#             */
/*   Updated: 2022/12/13 15:12:55 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[x] && x < len)
	{
		if (haystack[x] == needle[0])
		{
			y = 1;
			while (haystack[x + y] == needle[y] && (x + y) < len && needle[y])
				++y;
			if (needle[y] == '\0')
				return ((char *)&haystack[x]);
		}
		++x;
	}
	return (NULL);
}
