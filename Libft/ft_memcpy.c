/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:25:48 by itrueba-          #+#    #+#             */
/*   Updated: 2022/12/01 12:40:48 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	len;

	if (!dst && !src)
		return (0);
	len = 0;
	while (len < n)
	{
		((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		len++;
	}
	return (dst);
}	
