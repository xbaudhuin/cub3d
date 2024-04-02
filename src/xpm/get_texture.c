/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:48:06 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 13:10:02 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

t_xpm	*get_texture(char *path, void *mlx_ptr)
{
	t_xpm	*xpm;

	xpm = ft_calloc(sizeof(*xpm), 1);
	if (xpm == NULL)
		return (NULL);
	xpm->img = mlx_xpm_file_to_image(mlx_ptr, path, &xpm->width, &xpm->height);
	if (xpm->img == NULL)
	{
		free(xpm);
		return (NULL);
	}
	return (xpm);
}
