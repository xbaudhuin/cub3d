/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_delta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:56:49 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/02 12:56:50 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_delta_x(t_data_exec *data)
{
	if (data->ray_dir_x == 0)
	{
		return(1000000000000000000000000000000.0);
	}
	else
	{
		return(fabs(1 / data->ray_dir_x));
	}
}

static double	get_delta_y(t_data_exec *data)
{
	if (data->ray_dir_y == 0)
	{
		return(1000000000000000000000000000000.0);
	}
	else
	{
		return(fabs(1 / data->ray_dir_y));
	}
}

void	calculate_delta(t_data_exec *data)
{
	data->delta_dist_x = get_delta_x(data);
	data->delta_dist_y = get_delta_y(data);
}
