/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:22:57 by itrueba-          #+#    #+#             */
/*   Updated: 2022/12/13 17:54:09 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compare(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_compare(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	end--;
	while (s1[end] && ft_compare(s1[end], set))
		end--;
	len = end - start + 2;
	ptr = (char *)malloc((len) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], len);
	return (ptr);
}
