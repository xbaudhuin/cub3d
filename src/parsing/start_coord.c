/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:45:05 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/03 19:11:24 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_direction(const char c)
{
	if (c == 'N')
		return (NORTH);
	else if (c == 'S')
		return (SOUTH);
	else if (c == 'E')
		return (EAST);
	else
		return (WEST);
}

t_start_coord	get_start_coord(char **map)
{
	t_start_coord	start;
	unsigned int	x;
	unsigned int	y;

	ft_bzero(&start, sizeof(start));
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (is_player_char(map[x][y]) == TRUE)
			{
				start.x = (double)x;
				start.y = (double)y;
				start.direction = get_direction(map[x][y]);
				break ;
			}
			y++;
		}
		x++;
	}
	return (start);
}
