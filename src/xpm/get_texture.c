/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:48:06 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/08 14:18:42 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
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
			ft_fprintf(2, RED"Error\n"RESET"In get_texture_img_from_xpm: "
				"Fail in mlx_xpm_file_to_image\n");
			return (free_texture(texture, mlx_ptr), NULL);
		}
		texture[i]->img->address = (int *)mlx_get_data_addr(
			texture[i]->img->mlx_img, &texture[i]->img->bpp, &texture[i]->img->line_size, &texture[i]->img->endiant);
		if (texture[i]->img->address == NULL)
		{
			ft_fprintf(2, RED"Error\n"RESET"In get_texture_img_from_xpm: "
				"Fail in mlx_xpm_file_to_image\n");
			return (free_texture(texture, mlx_ptr), NULL);
		}
		i++;
	}
	return (texture);
}
