/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_move_available.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:57:24 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/03 14:57:25 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern int world_map[MAP_HEIGHT][MAP_WIDTH];

int	double_sign(double n)
{
	if (n < 0)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

int	is_move_available(int move_axe, int	new_pos, t_data_exec *data)
{
	if (move_axe == X)
	{
		if (world_map[new_pos][(int)(data->pos_y)] == 0 && world_map[new_pos + double_sign(data->dir_x)][(int)(data->pos_y)] == 0)
			return (TRUE);
		else
			return (FALSE);
	}
	else
	{
		if (world_map[(int)(data->pos_x)][new_pos] == 0 && world_map[(int)(data->pos_x)][new_pos + double_sign(data->dir_y)] == 0)
			return (TRUE);
		else
			return (FALSE);
	}
}
