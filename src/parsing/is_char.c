/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:29:25 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 18:29:55 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player_char(const char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (TRUE);
	return (FALSE);
}

int	is_map_char(const char c)
{
	if (c == '0' || c == '1')
		return (TRUE);
	if (is_player_char(c) == TRUE)
		return (TRUE);
	return (FALSE);
}
