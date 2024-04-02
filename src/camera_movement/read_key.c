/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:42:12 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/03/29 16:42:13 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_movement(int keysym)
{
	if (keysym == A_KEY || keysym == S_KEY
		|| keysym == D_KEY || keysym == W_KEY)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

static int	is_rotate(int keysym)
{
	if (keysym == LEFT_ARROW || keysym == RIGTH_ARROW)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

static int	is_escape(int keysim)
{
	if (keysim == ESCAPE)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int	read_key(int keysym, t_data_exec *data)
{
	if (is_movement(keysym) == TRUE)
	{
		move(keysym, data);
	}
	else if (is_rotate(keysym) == TRUE)
	{
		rotate(keysym, data);
	}
	else if (is_escape(keysym) == TRUE)
	{
		end_process(data);
	}
	draw_pov(data);
	return (SUCCESS);
}