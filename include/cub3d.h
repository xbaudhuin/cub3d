/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:03:50 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/03 19:12:07 by xabaudhu         ###   ########.fr       */
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

# define X 1
# define Y 2

# define WIDTH 1920
# define HEIGHT 1080

# define ROTATE_SPEED 3.14 / 2
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

enum	e_direction
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
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
	char		**map;
}				t_data;

typedef struct s_start_coord
{
	double	x;
	double	y;
	int		direction;
}			t_start_coord;

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
	int		step_x;
	int		step_y;
	int		side;
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
void	draw_wall_line(t_img img, int x, double perp_wall_dist,
			t_data_exec *data);
void	rotate(int keysim, t_data_exec *data);
void	do_dda(t_data_exec *data);
void	calculate_delta(t_data_exec *data);
void	calculate_step(t_data_exec *data);
double	calculate_perp_wall_dist(t_data_exec *data);
int		end_process(t_data_exec *data);
int		is_move_available(int move_axe, int	new_pos, t_data_exec *data);

//PARSING

t_data			*open_map(char *filename);
int				get_color_from_file(const char *line, int *error, int bit_shift);
void			print_data(t_data *data);
char			**parse_map(int fd);
int				check_map(t_vector *vector);
t_start_coord	get_start_coord(char **map);
int				check_current_line(const char *line,
					unsigned int *i, t_texture *texture);

//IS CHAR

int	is_player_char(const char c);
int	is_map_char(const char c);
// PARSING_UTILS

unsigned int	skip_spaces(const char *line);
unsigned int	skip_space_digit(const char *line);
int				atoi_color(const char *line, int *error);
int				print_error(const char *line);
void			ft_parse_map_error(int error);
char			*skip_empty_line(int fd);
//FREE FUNCTION

void	free_data(t_data *data);
void	free_texture(t_texture *texture);

#endif
