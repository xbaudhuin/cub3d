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

extern int world_map[MAP_HEIGHT][MAP_WIDTH];

static int	get_line_height(double perp_wall_dist)
{
	int	line_height;

	line_height = (int)(HEIGHT / perp_wall_dist);
	return (line_height);
}

static int	get_draw_start(int line_height)
{
	int draw_start;

	draw_start = (-line_height / 2) + (HEIGHT / 2);
	if (draw_start < 0)
	{
		draw_start = 0;
	}
	return (draw_start);
}

static int	get_draw_end(int line_height)
{
	int draw_end;

	draw_end = (line_height / 2) + (HEIGHT / 2);
	if (draw_end > HEIGHT)
	{
		draw_end = HEIGHT - 1;
	}
	return (draw_end);
}

void	draw_wall_line(t_img img, int x, double perp_wall_dist,
			t_data_exec *data)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = get_line_height(perp_wall_dist);
	draw_start = get_draw_start(line_height);
	draw_end = get_draw_end(line_height);
	int color;
	switch(world_map[data->map_x][data->map_y])
	{
		case 1:  color = 0xFFFFFF;  break; //red
		case 2:  color = 0xFF00FF;  break; //green
		case 3:  color = 0x0000FF;   break; //blue
		case 4:  color = 0x00FFFF;  break; //white
		default: color = 0xFFFF00; break; //yellow
	} 
	draw_line_on_img(img, x, draw_start, x, draw_end, color);
}
