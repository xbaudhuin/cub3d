/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:46:06 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/02 15:46:07 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_process(t_data_exec *data)
{
	if (data->win != NULL && data->mlx != NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	free_data(data->file);
	exit(0);
	return (0);
}
