/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:16:56 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/09 14:41:53 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_texture
{
	char			*path;
	struct s_img	*img;

}			t_texture;

typedef struct s_data
{
	t_texture	**texture;
	int			color_floor;
	int			color_ceiling;
	char		**map;
}			t_data;

typedef struct s_start_coord
{
	double	x;
	double	y;
	int		direction;
}		t_start_coord;

typedef struct s_img
{
	void	*mlx_img;
	int		*address;
	int		width;
	int		height;
	int		line_size;
	int		bpp;
	int		endiant;
}		t_img;

typedef struct s_draw_line
{
	int	height;
	int	start;
	int	end;
	int	color;
}		t_draw_line;

typedef struct s_draw_texture
{
	double		step;
	double		pos;
	int			y;
	int			x;
	int			height;
}		t_draw_texture;

typedef struct s_data_exec
{
	t_data	*file;
	void	*mlx;
	void	*win;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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
	double	hit_pos;
	int		old_mouse_x;
}				t_data_exec;

#endif
