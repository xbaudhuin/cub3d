/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:34:46 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/03/26 15:34:47 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	get_new_img(void *mlx, int width, int height)
{
	t_img	new_img;

	new_img.mlx_img = mlx_new_image(mlx, width, height);
	if (new_img.mlx_img == NULL)
	{
		return (new_img);
	}
	new_img.address = (int *)mlx_get_data_addr(new_img.mlx_img, &new_img.bpp,
			&new_img.line_size, &new_img.endiant);
	new_img.width = width;
	new_img.height = height;
	return (new_img);
}
