/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:03:50 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/09 11:58:58 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structures.h"
# include "libft.h"
# include "vector.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <math.h>
# include "mlx.h"
# include <time.h>
# include "X11/keysym.h"
# include "X11/keysymdef.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include "draw.h"
# include "camera_movement.h"
# include "raycasting.h"
# include "parsing.h"

# define RESET  "\x1B[0m"
# define RED "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

# define SUCCESS 0
# define FAILURE 1

# define FALSE 0
# define TRUE 1

enum	e_parsing_error
{
	UNCLOSED_MAP = 2,
	INVALID_PLAYER = 3,
	INVALID_TEXTURE = 4,
	INVALID_COLOR = 5,
	INVALID_LINE = 6,
	INVALID_CHAR = 7,
};

enum	e_direction
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
	NB_TEXTURE = 4,
};

t_img			get_new_img(void *mlx, int width, int height);
int				end_process(t_data_exec *data);

#endif
