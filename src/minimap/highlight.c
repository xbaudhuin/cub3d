/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:49:12 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/11 18:49:57 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	line_highlight(t_img *img, int line)
{
	int	color;
	int	row;
	int	limit;

	color = 0x000000;
	row = 6;
	limit = line + 4;
	while (line < limit)
	{
		row = 8;
		while (row < 334)
		{
			put_pixel_on_img(*img, row, line, color);
			row++;
		}
		line++;
	}
}

static void	row_hightlight(t_img *img, int row)
{
	int	color;
	int	line;
	int	limit;

	color = 0x000000;
	line = 6;
	limit = row + 4;
	while (row < limit)
	{
		line = 8;
		while (line < 174)
		{
			put_pixel_on_img(*img, row, line, color);
			line++;
		}
		row++;
	}
}

void	hightlight_minimap(t_img *img)
{
	line_highlight(img, 6);
	line_highlight(img, 170);
	row_hightlight(img, 6);
	row_hightlight(img, 330);
}
