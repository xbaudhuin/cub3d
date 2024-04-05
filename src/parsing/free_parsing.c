/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:00:49 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/05 12:33:48 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_texture **texture)
{
	unsigned int	i;

	i = 0;
	if (texture == NULL)
		return ;
	while (i < NB_TEXTURE)
	{
		free(texture[i]->img);
		free(texture[i]->path);
		free(texture[i]);
		texture[i] = NULL;
		i++;
	}
	free(texture);
}

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->texture != NULL)
		free_texture(data->texture);
	data->texture = NULL;
	if (data->map != NULL)
		free_split(data->map);
	data->map = NULL;
	free(data);
}
