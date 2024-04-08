/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:49:38 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/05 14:49:39 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_x(t_data_exec *data)
{
	int		texture_x;
	int		texture_width;

	texture_width = data->file->texture[hit_dir(data)]->img->width;
	texture_x = (int)(data->hit_pos * (double)texture_width);
	return (texture_x);
}
