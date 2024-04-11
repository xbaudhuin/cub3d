/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:12:49 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/11 18:53:11 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_block(t_img *img, const char c, int line_img, int row_img)
{
	int	x_img;
	int	y_img;
	int	color;

	color = get_color_for_block(c);
	x_img = line_img * 10;
	y_img = row_img * 10;
	while (x_img < line_img * 10 + 10)
	{
		y_img = row_img * 10;
		while (y_img < row_img * 10 + 10)
		{
			put_pixel_on_img(*img, y_img, x_img, color);
			y_img++;
		}
		x_img++;
	}
}

static void	fill_line_null(t_img *img, int line_img)
{
	int	offset;

	offset = -16;
	while (offset < 16)
	{
		fill_block(img, 0, line_img, offset + 17);
		offset++;
	}
}

static void	fill_line(t_data_exec *data, t_img *img, int x, int line_img)
{
	int	y_player;
	int	y;
	int	len_line;
	int	offset;

	y_player = (int)data->pos_y;
	offset = -16;
	y = y_player + offset;
	len_line = ft_strlen(data->file->map[x]) - 1;
	while (offset < 16)
	{
		if (y >= len_line || y < 0)
			fill_block(img, 0, line_img, offset + 17);
		else
		{
			if (is_player(data, x, y) == TRUE)
				fill_block(img, 'p', line_img, offset + 17);
			else
				fill_block(img, data->file->map[x][y], line_img, offset + 17);
		}
		y++;
		offset++;
	}
}

void	get_minimap(t_data_exec *data, t_img *img)
{
	int	x_player;
	int	x;
	int	offset;

	x_player = (int)data->pos_x;
	offset = -8;
	x = x_player + offset;
	hightlight_minimap(img);
	while (offset < 8)
	{
		if (x < 0 || data->file->map[x] == NULL)
		{
			fill_line_null(img, offset + 9);
		}
		else
			fill_line(data, img, x, offset + 9);
		x++;
		offset++;
	}
}
