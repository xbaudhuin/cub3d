/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_on_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:13:00 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/03/26 13:13:02 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_on_img(t_img img, int x, int y, int color)
{
	// int i = 0;
	// while (1)
	// {
	// 	printf("i = %d\n", i);
	// 	img.address[HEIGHT * (WIDTH + i)] = 0;
	// 	i++;
	// }
	// exit(0);
	if (y * img.width + x > WIDTH * HEIGHT)
		return ;
	img.address[y * img.width + x ] = color;
}
