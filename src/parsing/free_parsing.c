/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:00:49 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/08 16:26:39 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_texture **texture, void *mlx_ptr)
{
	unsigned int	i;

	i = 0;
	if (texture == NULL)
		return ;
	while (i < NB_TEXTURE)
	{
		if (mlx_ptr != NULL && texture[i]->img->mlx_img != NULL)
			mlx_destroy_image(mlx_ptr, texture[i]->img->mlx_img);
		free(texture[i]->img);
		texture[i]->img = NULL;
		free(texture[i]->path);
		texture[i]->path = NULL;
		free(texture[i]);
		texture[i] = NULL;
		i++;
	}
	free(texture);
}

void	free_data(t_data *data, void *mlx_ptr)
{
	if (data == NULL)
		return ;
	if (data->texture != NULL)
		free_texture(data->texture, mlx_ptr);
	data->texture = NULL;
	if (data->map != NULL)
		free_split(data->map);
	data->map = NULL;
	free(data);
}
