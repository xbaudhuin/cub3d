/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:22:45 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/10 16:22:46 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_door(t_data_exec *data)
{
	if (data->file->map[(int)(data->pos_x
				+ data->dir_x)][(int)(data->pos_y + data->dir_y)] == CLOSE_DOOR)
	{
		data->file->map[(int)(data->pos_x
				+ data->dir_x)][(int)(data->pos_y + data->dir_y)] = OPEN_DOOR;
	}
	else if (data->file->map[(int)(data->pos_x
				+ data->dir_x)][(int)(data->pos_y + data->dir_y)] == OPEN_DOOR)
	{
		data->file->map[(int)(data->pos_x
				+ data->dir_x)][(int)(data->pos_y + data->dir_y)] = CLOSE_DOOR;
	}
}
