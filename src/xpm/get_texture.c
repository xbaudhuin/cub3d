/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:48:06 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/08 16:41:28 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"
#include "structures.h"

t_texture	**get_texture_img_from_xpm(t_texture **tex, void *mlx_ptr)
{
	unsigned int	i;

	i = 0;
	while (i < NB_TEXTURE)
	{
		tex[i]->img->mlx_img = mlx_xpm_file_to_image(mlx_ptr,
				tex[i]->path, &tex[i]->img->width, &tex[i]->img->height);
		if (tex[i]->img->mlx_img == NULL)
		{
			ft_fprintf(2, RED"Error\n"RESET"In get_texture_img_from_xpm: "
				"Fail in mlx_xpm_file_to_image\n");
			return (free_texture(tex, mlx_ptr), NULL);
		}
		tex[i]->img->address = (int *)mlx_get_data_addr(tex[i]->img->mlx_img,
				&tex[i]->img->bpp, &tex[i]->img->line_size,
				&tex[i]->img->endiant);
		if (tex[i]->img->address == NULL)
		{
			ft_fprintf(2, RED"Error\n"RESET"In get_tex_img_from_xpm: "
				"Fail in mlx_xpm_file_to_image\n");
			return (free_texture(tex, mlx_ptr), NULL);
		}
		i++;
	}
	return (tex);
}
