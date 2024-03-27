/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:35:43 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/03/27 17:35:46 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_img img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < img.width)
	{
		y = img.height / 2;
		while (y < img.height)
		{
			put_pixel_on_img(img, x, y, color);
			++y;
		}
		++x;
	}
}
