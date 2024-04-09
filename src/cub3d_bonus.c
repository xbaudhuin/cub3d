/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:40:10 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/09 14:42:58 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_nb_arg(int ac)
{
	if (ac != 2)
	{
		ft_fprintf(2, "cub3d: error: need one argument\n");
		exit (1);
	}
}

static void	init_value(t_data_exec *data)
{
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->old_mouse_x = WIDTH / 2;
	data->mlx = mlx_init();
	if (data->mlx != NULL)
	{
		data->win = mlx_new_window(data->mlx, WIDTH,
				HEIGHT, "cub3d");
	}
}

static t_data_exec	get_init_data(char *path)
{
	t_data_exec		data;
	t_start_coord	start;

	ft_bzero(&data, sizeof(data));
	init_value(&data);
	if (data.mlx == NULL || data.win == NULL)
	{
		ft_fprintf(2, "cub3d: init mlx pointers: error\n");
		end_process(&data);
	}
	data.file = open_map(path, data.mlx);
	if (data.file == NULL)
	{
		end_process(&data);
	}
	start = get_start_coord(data.file->map);
	data.pos_x = start.x + 0.5;
	data.pos_y = start.y + 0.5;
	starting_rotate(&data, start.direction);
	return (data);
}

int	main(int ac, char **av)
{
	t_data_exec	data;

	check_nb_arg(ac);
	data = get_init_data(av[1]);
	if (data.mlx == NULL || data.win == NULL)
	{
		exit(1);
	}
	draw_pov(&data);
	mlx_mouse_move(data.mlx, data.win, WIDTH * 0.5,
		HEIGHT * 0.5);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, &mouse_rotate, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &read_key, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
		&end_process, &data);
	mlx_loop(data.mlx);
}
