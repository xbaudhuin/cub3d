/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:56:41 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 17:58:33 by xabaudhu         ###   ########.fr       */
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

static	void	print_texture(t_texture *texture)
{
	if (texture == NULL)
		return ;
	ft_printf(BLU"texture->NO ="RESET" %s\n", texture->NO);
	ft_printf(BLU"texture->SO ="RESET" %s\n", texture->SO);
	ft_printf(BLU"texture->NO ="RESET" %s\n", texture->WE);
	ft_printf(BLU"texture->NO ="RESET" %s\n", texture->EA);
	ft_printf(BLU"texture->color_ceiling ="RESET" %d\n", texture->color_ceiling);
	ft_printf(BLU"texture->color_floor ="RESET" %d\n", texture->color_floor);
}

void	print_data(t_data *data)
{
	if (data == NULL)
		return ;
	print_texture(data->texture);
	print_map(data->map);
}
