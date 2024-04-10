/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:32:19 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/09 13:27:58 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_data_exec *data)
{
	if (is_walkable(data->file->map[(int)(data->pos_x
				+ data->dir_x * MOVE_SPEED)][(int)(data->pos_y)]) == TRUE)
	{
		data->pos_x += data->dir_x * MOVE_SPEED;
	}
	if (is_walkable(data->file->map[(int)(data->pos_x)][(int)(data->pos_y
		+ data->dir_y * MOVE_SPEED)]) == TRUE)
	{
		data->pos_y += data->dir_y * MOVE_SPEED;
	}
}

static void	move_backward(t_data_exec *data)
{
	if (is_walkable(data->file->map[(int)(data->pos_x
				- data->dir_x * MOVE_SPEED)][(int)(data->pos_y)]) == TRUE)
	{
		data->pos_x -= data->dir_x * MOVE_SPEED;
	}
	if (is_walkable(data->file->map[(int)(data->pos_x)][(int)(data->pos_y
		- data->dir_y * MOVE_SPEED)]) == TRUE)
	{
		data->pos_y -= data->dir_y * MOVE_SPEED;
	}
}

static void	move_left(t_data_exec *data)
{
	if (is_walkable(data->file->map[(int)(data->pos_x
				- data->plane_x * MOVE_SPEED)][(int)(data->pos_y)]) == TRUE)
	{
		data->pos_x -= data->plane_x * MOVE_SPEED;
	}
	if (is_walkable(data->file->map[(int)(data->pos_x)][(int)(data->pos_y
		- data->plane_y * MOVE_SPEED)]) == TRUE)
	{
		data->pos_y -= data->plane_y * MOVE_SPEED;
	}
}

static void	move_rigth(t_data_exec *data)
{
	if (is_walkable(data->file->map[(int)(data->pos_x
				+ data->plane_x * MOVE_SPEED)][(int)(data->pos_y)]) == TRUE)
	{
		data->pos_x += data->plane_x * MOVE_SPEED;
	}
	if (is_walkable(data->file->map[(int)(data->pos_x)][(int)(data->pos_y
		+ data->plane_y * MOVE_SPEED)]) == TRUE)
	{
		data->pos_y += data->plane_y * MOVE_SPEED;
	}
}

void	move(int keysim, t_data_exec *data)
{
	if (keysim == W_KEY)
	{
		move_forward(data);
	}
	else if (keysim == S_KEY)
	{
		move_backward(data);
	}
	else if (keysim == A_KEY)
	{
		move_left(data);
	}
	else if (keysim == D_KEY)
	{
		move_rigth(data);
	}
}
