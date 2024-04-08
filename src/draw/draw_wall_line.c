/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:02:59 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/02 16:03:03 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_line_height(double perp_wall_dist)
{
	int	line_height;

	line_height = (int)(HEIGHT / perp_wall_dist);
	return (line_height);
}

static int	get_draw_start(int line_height)
{
	int	draw_start;

	draw_start = (HEIGHT - line_height) / 2;
	if (draw_start < 0)
	{
		draw_start = 0;
	}
	return (draw_start);
}

static int	get_draw_end(int line_height)
{
	int	draw_end;

	draw_end = (HEIGHT + line_height) / 2;
	if (draw_end > HEIGHT || draw_end < 0)
	{
		draw_end = HEIGHT;
	}
	return (draw_end);
}

void	draw_wall_line(t_img img, int x, double perp_wall_dist,
			t_data_exec *data)
{
	t_draw_line		line;
	t_draw_texture	txt;
	int				y;

	line.height = get_line_height(perp_wall_dist);
	line.start = get_draw_start(line.height);
	line.end = get_draw_end(line.height);
	txt.height = data->file->texture[hit_dir(data)]->img->height;
	txt.x = get_texture_x(data);
	txt.step = 1.0 * txt.height / line.height;
	txt.pos = (line.start - HEIGHT / 2 + line.height / 2) * txt.step;
	y = line.start;
	while (y < line.end)
	{
		txt.y = (int)txt.pos & (txt.height - 1);
		txt.pos += txt.step;
		line.color = data->file->texture[hit_dir(data)]
			->img->address[txt.height * txt.y + txt.x];
		put_pixel_on_img(img, x, y, line.color);
		++y;
	}
}
