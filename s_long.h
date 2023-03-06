/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_long.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:47:45 by itrueba-          #+#    #+#             */
/*   Updated: 2023/03/06 20:26:16 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LONG_H
# define S_LONG_H

# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	size_t	line;
	size_t	line_long;
	size_t c;
	size_t e;
	size_t p;
}						t_map;

void	ft_check_map(char *map_name);
void	ft_error(char *text, t_map *map);

#endif