/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:44:30 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/09 10:44:31 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	move_mouse_on_edge(t_data_exec *data, int x, int y)
{
	if (x > WIDTH - MOUSE_LIMIT)
	{
		mlx_mouse_move(data->mlx, data->win, MOUSE_LIMIT, y);
	}
	if (x < MOUSE_LIMIT)
	{
		mlx_mouse_move(data->mlx, data->win, WIDTH - MOUSE_LIMIT, y);
	}
}

int	mouse_rotate(int x, int y, t_data_exec *data)
{
	move_mouse_on_edge(data, x, y);
	if (x == data->old_mouse_x)
		return (0);
	else if (x < data->old_mouse_x)
	{
		rotate(LEFT_ARROW, data);
	}
	else if (x > data->old_mouse_x)
	{
		rotate(RIGTH_ARROW, data);
	}
	data->old_mouse_x = x;
	draw_pov(data);
	return (0);
}
