/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:42:59 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/05 14:42:59 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_hit_pos(t_data_exec *data, double perp_wall_dist)
{
	double	hit_pos;

	if (data->side == 0)
	{
		hit_pos = data->pos_y + perp_wall_dist * data->ray_dir_y;
	}
	else
	{
		hit_pos = data->pos_x + perp_wall_dist * data->ray_dir_x;
	}
	hit_pos = hit_pos - floor(hit_pos);
	return (hit_pos);
}
