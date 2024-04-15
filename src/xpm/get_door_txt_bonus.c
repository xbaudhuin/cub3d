/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_txt_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:32:46 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/10 14:32:47 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_door(t_img **door_txt, t_data_exec *data)
{
	int	i;

	i = 0;
	while (i < NB_DOOR_TXT)
	{
		if ((*door_txt)[i].mlx_img != NULL)
		{
			mlx_destroy_image(data->mlx, (*door_txt)[i].mlx_img);
		}
		++i;
	}
	free(*door_txt);
	*door_txt = NULL;
}

static void	get_mlx_img(t_img *door_txt, t_data_exec *data)
{
	door_txt[0].mlx_img = mlx_xpm_file_to_image(data->mlx,
			DOOR_1_PATH, &door_txt[0].width, &door_txt[0].height);
	door_txt[1].mlx_img = mlx_xpm_file_to_image(data->mlx,
			DOOR_2_PATH, &door_txt[1].width, &door_txt[1].height);
	door_txt[2].mlx_img = mlx_xpm_file_to_image(data->mlx,
			DOOR_3_PATH, &door_txt[2].width, &door_txt[2].height);
	door_txt[3].mlx_img = mlx_xpm_file_to_image(data->mlx,
			DOOR_4_PATH, &door_txt[3].width, &door_txt[3].height);
	door_txt[4].mlx_img = mlx_xpm_file_to_image(data->mlx,
			DOOR_5_PATH, &door_txt[4].width, &door_txt[4].height);
	door_txt[5].mlx_img = mlx_xpm_file_to_image(data->mlx,
			DOOR_6_PATH, &door_txt[5].width, &door_txt[5].height);
}

static void	get_addr_img(t_img **door_txt, t_data_exec *data)
{
	int	i;

	i = 0;
	while (i < NB_DOOR_TXT)
	{
		if ((*door_txt)[i].mlx_img == NULL)
		{
			ft_fprintf(2, "cub3d: get door textures: error\n");
			free_door(door_txt, data);
			return ;
		}
		(*door_txt)[i].address = (int *)mlx_get_data_addr(
				(*door_txt)[i].mlx_img,
				&(*door_txt)[i].bpp, &(*door_txt)[i].line_size,
				&(*door_txt)[i].endiant);
		if ((*door_txt)[i].address == NULL)
		{
			ft_fprintf(2, "cub3d: get door textures: error\n");
			free_door(door_txt, data);
			return ;
		}
		++i;
	}
}

t_img	*get_door_txt(t_data_exec *data)
{
	t_img	*door_txt;

	door_txt = ft_calloc(NB_DOOR_TXT, sizeof (*door_txt));
	if (door_txt == NULL)
	{
		return (NULL);
	}
	get_mlx_img(door_txt, data);
	get_addr_img(&door_txt, data);
	return (door_txt);
}
