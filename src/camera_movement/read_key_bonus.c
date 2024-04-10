/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:21:38 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/10 16:21:39 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	else if (keysym == SPACE)
	{
		check_door(data);
	}
	draw_pov(data);
	return (SUCCESS);
}
