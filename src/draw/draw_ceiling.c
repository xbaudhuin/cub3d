/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:29:02 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/03/27 17:29:03 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_img img, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < img.width)
	{
		y = 0;
		while (y < img.height / 2)
		{
			put_pixel_on_img(img, x, y, color);
			++y;
		}
		++x;
	}
}
