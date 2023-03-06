/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:02 by itrueba-          #+#    #+#             */
/*   Updated: 2022/12/01 16:52:38 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			x;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	x = 0;
	while (x < n)
	{
		if (str1[x] != str2[x])
			return ((int)(str1[x] - str2[x]));
		x++;
	}
	return (0);
}
