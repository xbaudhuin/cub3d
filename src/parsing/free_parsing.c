/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:00:49 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 18:02:06 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(t_texture *texture)
{
	if (texture == NULL)
		return ;
	if (texture->NO != NULL)
		free(texture->NO);
	if (texture->EA != NULL)
		free(texture->EA);
	if (texture->WE != NULL)
		free(texture->WE);
	if (texture->SO != NULL)
		free(texture->SO);
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
