/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:51:18 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/13 14:39:33 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(t_data_exec *data, int x, int y)
{
	if (x == (int)data->pos_x && y == (int)data->pos_y)
		return (TRUE);
	return (FALSE);
}

int	get_color_for_block(const char c)
{
	if (c == '\0' || c == '1' || c == ' ')
		return (0x4E4D4D);
	if (c == 'p')
		return (0xDE1111);
	if (c == '0')
		return (0xbbbbbd);
	if (c >= '2' && c < '7')
		return (0xCC00CC);
	if (c == '7')
		return (0xFF66B2);
	return (0);
}
