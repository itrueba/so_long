/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:23:11 by itrueba-          #+#    #+#             */
/*   Updated: 2022/12/13 15:09:29 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_chr;

	last_chr = 0;
	while (*s)
	{
		if (*s == (char)c)
			last_chr = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last_chr);
}
