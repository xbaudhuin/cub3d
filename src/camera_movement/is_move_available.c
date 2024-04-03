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
		if (data->parse_data->map[new_pos][(int)(data->pos_y)] == 0 && data->parse_data->map[new_pos + double_sign(data->dir_x)][(int)(data->pos_y)] == 0)
			return (TRUE);
		else
			return (FALSE);
	}
	else
	{
		if (data->parse_data->map[(int)(data->pos_x)][new_pos] == 0 && data->parse_data->map[(int)(data->pos_x)][new_pos + double_sign(data->dir_y)] == 0)
			return (TRUE);
		else
			return (FALSE);
	}
}
