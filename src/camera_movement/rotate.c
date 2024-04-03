/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:32:26 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/03/29 16:32:28 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_left(t_data_exec *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(ROTATE_SPEED)
		- data->dir_y * sin(ROTATE_SPEED);
	data->dir_y = old_dir_x * sin(ROTATE_SPEED)
		+ data->dir_y * cos(ROTATE_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(ROTATE_SPEED)
		- data->plane_y * sin(ROTATE_SPEED);
	data->plane_y = old_plane_x * sin(ROTATE_SPEED)
		+ data->plane_y * cos(ROTATE_SPEED);		
}

static void	rotate_rigth(t_data_exec *data)
{
	double	old_dir_x;
	double	old_plane_x;
	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-ROTATE_SPEED)
		- data->dir_y * sin(-ROTATE_SPEED);
	data->dir_y = old_dir_x * sin(-ROTATE_SPEED)
		+ data->dir_y * cos(-ROTATE_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-ROTATE_SPEED)
		- data->plane_y * sin(-ROTATE_SPEED);
	data->plane_y = old_plane_x * sin(-ROTATE_SPEED)
		+ data->plane_y * cos(-ROTATE_SPEED);	
}

void	rotate(int keysim, t_data_exec *data)
{
	if (keysim == RIGTH_ARROW)
	{
		rotate_rigth(data);
	}
	else if (keysim == LEFT_ARROW)
	{
		rotate_left(data);
	}
}
