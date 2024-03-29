/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:03:50 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/03/29 16:46:22 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "vector.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <math.h>
# include "X11/keysym.h"
# include "X11/keysymdef.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>

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

# define WIDTH 1920.0
# define HEIGHT 1080.0

typedef struct s_texture
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		color_floor;
	int		color_ceiling;
}			t_texture;

typedef struct s_data
{
	t_texture	*texture;
	char		**map;
}				t_data;


#endif
