/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:12:49 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/11 14:28:16 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include "libft.h"
#include "mlx.h"
#include "structures.h"
#include <math.h>

int	get_color_for_block(const char c)
{
	if (c == '\0' || c == '1' || c == ' ')
		return (0x0018f2);
	if (c == 'p')
		return (0x921e12);
	if (c == '0')
		return (0xbbbbbd);
	if (c >= '2' && c < '7')
		return (0x144803);
	if (c == '7')
		return (0x35bd07);
	return (0);
}

void	fill_block(t_img *img, const char c, int line_img, int row_img)
{
	int	x_img;
	int	y_img;
	int	color;
	
	color = get_color_for_block(c);
	x_img = line_img * 10;
	y_img = row_img * 10;
	printf("x_img = %d, y_img = %d\n", x_img, y_img);
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

void	fill_line_null(t_img *img, int line_img)
{
	int	offset;

	offset = -8;
	while (offset < 8)
	{
		fill_block(img, 0, line_img, offset + 9);
		offset++;
	}
}

int	is_player(t_data_exec *data, int x, int y)
{
	if (x == (int)data->pos_x && y == (int)data->pos_y)
		return (TRUE);
	return (FALSE);
}

void	fill_line(t_data_exec *data, t_img *img, int x, int line_img)
{
	int	y_player;
	int	y;
	int	len_line;
	int	offset;

	y_player = (int)data->pos_y;
	offset = -8;
	y = y_player - 8;
	len_line = ft_strlen(data->file->map[x]) - 1;
	while (offset < 8)
	{
		if (y >= len_line || y < 0)
			fill_block(img, 0, line_img, offset + 9);
		else
		{
			if (is_player(data, x, y) == TRUE)
				fill_block(img, 'p', line_img, offset + 9);
			else
				fill_block(img, data->file->map[x][y], line_img, offset + 9);
		}
		y++;
		offset++;
	}
}

void	line_highlight(t_img *img, int line)
{
	int	color;
	int	row;
	int	limit;

	color = 0x000000;
	row = 8;
	limit = line + 3;
	while (line < limit)
	{
		row = 8;
		while (row < 172)
		{
			put_pixel_on_img(*img, row, line, color);
			row++;
		}
		line++;
	}
}

void	row_hightlight(t_img *img, int row)
{
	int	color;
	int	line;
	int	limit;

	color = 0x000000;
	line = 8;
	limit = row + 3;
	while (row < limit)
	{
		line = 8;
		while (line < 92)
		{
			put_pixel_on_img(*img, row, line, color);
			line++;
		}
		row++;
	}
}

void	hightlight_minimap(t_img *img)
{
	int	line;

	line = 8;
	line_highlight(img, 7);
	line_highlight(img, 90);
	row_hightlight(img, 7);
	row_hightlight(img, 170);
}

void	get_minimap(t_data_exec *data, t_img *img)
{
	int	x_player;
	int	x;
	int	offset;

	x_player = (int)data->pos_x;
	x = x_player - 4;
	offset = -4;
	hightlight_minimap(img);
	while (offset < 4)
	{
		if (x < 0 || data->file->map[x] == NULL)
		{
			fill_line_null(img, offset + 5);
		}
		else
			fill_line(data, img, x, offset + 5);
		x++;
		offset++;
	}
}
