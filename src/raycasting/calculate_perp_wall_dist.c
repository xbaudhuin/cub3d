/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_perp_wall_dist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:53:33 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/02 15:53:34 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_perp_wall_dist(t_data_exec *data)
{
	double	perp_wall_dist;

	if (data->side == 0)
	{
		perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	}
	else
	{
		perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	}
	return (perp_wall_dist);
}
