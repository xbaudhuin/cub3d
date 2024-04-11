/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pov_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:14:49 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/11 19:14:50 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	truncate_pos(t_data_exec *data)
{
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
}

static void	update_ray_dir(t_data_exec *data, int x)
{
	double	camera_x;

	camera_x = (2 * x / ((double)WIDTH)) - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * camera_x;
}

static void	draw_x_line(t_data_exec *data, int x, t_img img)
{
	double	perp_wall_dist;

	update_ray_dir(data, x);
	truncate_pos(data);
	calculate_delta(data);
	calculate_step(data);
	do_dda(data);
	perp_wall_dist = calculate_perp_wall_dist(data);
	data->hit_pos = get_hit_pos(data, perp_wall_dist);
	draw_wall_line(img, x, perp_wall_dist, data);
}

void	draw_pov(t_data_exec *data)
{
	t_img	img;
	int		x;

	img = get_new_img(data->mlx, WIDTH, HEIGHT);
	if (img.mlx_img == NULL || img.address == NULL)
	{
		ft_fprintf(2, "cub3d: get new image: error\n");
		end_process(data);
	}
	draw_ceiling(img, data->file->color_ceiling);
	draw_floor(img, data->file->color_floor);
	x = 0;
	while (x < WIDTH)
	{
		draw_x_line(data, x, img);
		++x;
	}
	get_minimap(data, &img);
	mlx_put_image_to_window(data->mlx, data->win, img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, img.mlx_img);
}
