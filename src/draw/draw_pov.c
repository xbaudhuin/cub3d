/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:49:30 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/02 15:49:31 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern int world_map[MAP_HEIGHT][MAP_WIDTH];

void	draw_pov(t_data_exec *data)
{
	t_img 	img;
	double	perp_wall_dist;
	int		x;

	img = get_new_img(data->mlx, WIDTH, HEIGHT);
	if (img.mlx_img == NULL || img.address == NULL)
	{
		ft_fprintf(2, "cub3d: get mlx immage: error\n");
		end_process(data);
	}
	draw_ceiling(img, 0xa2d2df);
	draw_floor(img, 0x4b5320);
	x = 0;
	while (x < WIDTH)
	{
		data->camera_x = (2 * x / ((double)WIDTH)) - 1;
		data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
		data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
		data->map_x = (int)data->pos_x;
		data->map_y = (int)data->pos_y;
		calculate_delta(data);
		calculate_step(data);
		do_dda(data);
		perp_wall_dist = calculate_perp_wall_dist(data);
		draw_wall_line(img, x, perp_wall_dist, data);
		++x;
	}
	mlx_put_image_to_window(data->mlx, data->win, img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, img.mlx_img);
}
