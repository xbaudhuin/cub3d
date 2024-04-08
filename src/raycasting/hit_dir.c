/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:09:20 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/05 15:09:20 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hit_dir(t_data_exec *data)
{
	if (data->side == 0)
	{
		if (data->ray_dir_x > 0)
		{
			return (NORTH);
		}
		else
		{
			return (SOUTH);
		}
	}
	else
	{
		if (data->ray_dir_y > 0)
		{
			return (WEST);
		}
		else
		{
			return (EAST);
		}
	}
}
