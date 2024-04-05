/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:48:06 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/05 14:55:19 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include "structures.h"

t_texture	**get_texture_img_from_xpm(t_texture **texture, void *mlx_ptr)
{
	unsigned int	i;

	i = 0;
	while (i < NB_TEXTURE)
	{
		texture[i]->img->mlx_img = mlx_xpm_file_to_image(
			mlx_ptr, texture[i]->path, &texture[i]->img->width, &texture[i]->img->height);
		if (texture[i]->img->mlx_img == NULL)
		{
			return (NULL);
		}
		texture[i]->img->address = (int *)mlx_get_data_addr(
			texture[i]->img->mlx_img, &texture[i]->img->bpp, &texture[i]->img->line_size, &texture[i]->img->endiant);
		if (texture[i]->img->address == NULL)
			return (NULL);
		i++;
	}
	return (texture);
}
