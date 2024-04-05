/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:42:59 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/05 14:42:59 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_wall_pos(t_data_exec *data, double perp_wall_dist)
{
	double	wall_pos;

	if (data->side == 0)
	{
		wall_pos = data->pos_y + perp_wall_dist * data->ray_dir_y;
	}
	else
	{
		wall_pos = data->pos_x + perp_wall_dist * data->ray_dir_x;
	}
	wall_pos = wall_pos - floor(wall_pos);
	return (wall_pos);
}