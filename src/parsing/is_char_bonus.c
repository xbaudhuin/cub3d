/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:45:58 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/10 11:45:59 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_player_char(const char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (TRUE);
	return (FALSE);
}

int	is_map_char(const char c)
{
	if (c == VOID || c == WALL || c == OPEN_DOOR || c == CLOSE_DOOR)
		return (TRUE);
	if (is_player_char(c) == TRUE)
		return (TRUE);
	return (FALSE);
}
