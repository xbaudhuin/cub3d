/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:29:51 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/04 14:29:52 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	rotate_value(int orientation)
{
	if (orientation == NORTH)
	{
		return (0);
	}
	else if (orientation == EAST)
	{
		return (M_PI_2);
	}
	else if (orientation == SOUTH)
	{
		return (M_PI);
	}
	else
	{
		return (3 * M_PI_2);
	}
}


void	starting_rotate(t_data_exec *data, int orientation)
{
	double	old_dir_x;
	double	old_plane_x;
	double	start_rotate_value;

	start_rotate_value = rotate_value(orientation);
	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-start_rotate_value)
		- data->dir_y * sin(-start_rotate_value);
	data->dir_y = old_dir_x * sin(-start_rotate_value)
		+ data->dir_y * cos(-start_rotate_value);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-start_rotate_value)
		- data->plane_y * sin(-start_rotate_value);
	data->plane_y = old_plane_x * sin(-start_rotate_value)
		+ data->plane_y * cos(-start_rotate_value);	
}
