/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:03:50 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 12:58:36 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

# define ESCAPE 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_ARROW 65361
# define RIGTH_ARROW 65363

# define FALSE 0
# define TRUE 1

# define WIDTH 1920
# define HEIGHT 1080

# define ROTATE_SPEED 0.2
# define MOVE_SPEED 0.2

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

enum	e_parsing_error
{
	UNCLOSED_MAP = 2,
	INVALID_PLAYER = 3,
	INVALID_TEXTURE = 4,
	INVALID_COLOR = 5,
	INVALID_LINE = 6,
	INVALID_CHAR = 7,
};

typedef struct s_xpm
{
	void	*img;
	int		height;
	int		width;
}			t_xpm;

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
	t_vector	*map;
}				t_data;

typedef struct s_img
{
	void	*mlx_img;
	int		*address;
	int		width;
	int		height;
	int		line_size;
	int		bpp;
	int		endiant;
}t_img;



typedef struct s_data_exec
{
	void	*mlx;
	void	*win;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_heigth;
	int		draw_start;
	int		draw_end;
}t_data_exec;

void	put_pixel_on_img(t_img img, int x, int y, int color);
t_img	get_new_img(void *mlx, int width, int height);
void	draw_line_on_img(t_img img, int start_x, int start_y, int end_x,
	int end_y, int color);
void	draw_ceiling(t_img img, int color);
void	draw_floor(t_img img, int color);
void	move(int keysim, t_data_exec *data);
int		read_key(int keysym, t_data_exec *data);
void	draw_pov(t_data_exec *data);
void	rotate(int keysim, t_data_exec *data);
void	do_dda(t_data_exec *data);
int		end_process(t_data_exec *data);

t_vector	*parse_map(int fd);

#endif
