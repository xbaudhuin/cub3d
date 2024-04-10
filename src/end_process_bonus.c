/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:52 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/10 15:15:53 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	end_process(t_data_exec *data)
{
	free_data(data->file, data->mlx);
	if (data->door_txt != NULL)
		free_door(&data->door_txt, data);
	if (data->win != NULL && data->mlx != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	exit(0);
	return (0);
}
