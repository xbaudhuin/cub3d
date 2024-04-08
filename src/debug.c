/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:56:41 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/08 14:39:27 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map(char **map)
{
	unsigned int	i;

	i = 0;
	if (map == NULL)
	{
		ft_printf(RED"NO MAP\n"RESET);
		return ;
	}
	ft_printf(YEL"\n\n\nMAP\n\n\n"RESET);
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

static	void	print_texture(t_texture **texture)
{
	unsigned int	i;

	if (texture == NULL)
		return ;
	i = 0;
	ft_printf(BLU"texture->NORTH ="RESET" %s\n", texture[i++]->path);
	ft_printf(BLU"texture->EAST ="RESET" %s\n", texture[i++]->path);
	ft_printf(BLU"texture->SOUTH ="RESET" %s\n", texture[i++]->path);
	ft_printf(BLU"texture->WEST ="RESET" %s\n", texture[i++]->path);
}

void	print_data(t_data *data)
{
	if (data == NULL)
		return ;
	print_texture(data->texture);
	ft_printf(BLU"texture->color_ceiling ="RESET" %d\n", data->color_ceiling);
	ft_printf(BLU"texture->color_floor ="RESET" %d\n", data->color_floor);
	print_map(data->map);
}
