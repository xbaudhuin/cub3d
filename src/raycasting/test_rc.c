#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24



int world_map[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct s_data2
{
	void	*mlx;
	void	*win;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double 	time;
	double	old_time;
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
	int		hit;
	int		side;
	int		line_heigth;
	int		draw_start;
	int		draw_end;
	double	frame_time;
	double	move_speed;
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

}	t_data2;

t_data2	get_init_data(void)
{
	t_data2	data;

	ft_bzero(&data, sizeof(data));
	data.pos_x = 2;
	data.pos_y = 2;
	data.dir_x = 1;
	data.dir_y = 0;
	data.plane_x = 0;
	data.plane_y = 0.66;
	data.mlx = mlx_init();
	if (data.mlx != NULL)
	{
		data.win = mlx_new_window(data.mlx, WIDTH,
			HEIGHT, "raycasting_test");
	}
	return (data);
}

int	end_process(t_data2 *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	calculate_delta(t_data2 *data)
{
	if (data->ray_dir_x == 0)
	{
		data->delta_dist_x = 1000000000000000000000000000000.0;
	}
	else
	{
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
	}
	if (data->ray_dir_y == 0)
	{
		data->delta_dist_y = 1000000000000000000000000000000.0;
	}
	else
	{
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
	}
}

void	calculate_step(t_data2 *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
	}
}

void	do_dda(t_data2 *data)
{
	data->hit = 0;
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (world_map[data->map_x][data->map_y] > 0)
		{
			data->hit = 1;
		}
	}
}

void	draw_pov(t_data2 *data)
{
	t_img img;

	img = get_new_img(data->mlx, WIDTH, HEIGHT);
	draw_ceiling(img, 0xa2d2df);
	draw_floor(img, 0x4b5320);
	for (int x = 0; x < WIDTH; x++)
	{
		data->camera_x = (2 * x / ((double)WIDTH)) - 1;
		data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
		data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
		data->map_x = (int)data->pos_x;
		data->map_y = (int)data->pos_y;
		calculate_delta(data);
		calculate_step(data);
		do_dda(data);
		if (data->side == 0)
		{
			data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
		}
		else
		{
			data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
		}
		data->line_heigth = (int)(HEIGHT / data->perp_wall_dist);
		data->draw_start = -(data->line_heigth / 2) + (HEIGHT / 2);
		if (data->draw_start < 0)
			data->draw_start = 0;
		data->draw_end = (data->line_heigth / 2) + (HEIGHT / 2);
		if (data->draw_end > HEIGHT)
			data->draw_end = HEIGHT - 1;
		int color;
		switch(world_map[data->map_x][data->map_y])
		{
			case 1:  color = 0xFF0000;  break; //red
			case 2:  color = 0x00FF00;  break; //green
			case 3:  color = 0x0000FF;   break; //blue
			case 4:  color = 0xFFFFFF;  break; //white
			default: color = 0xFFFF00; break; //yellow
		} 
		draw_line_on_img(img, x, data->draw_start, x, data->draw_end, color);
	}
	mlx_put_image_to_window(data->mlx, data->win, img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, img.mlx_img);
}

void	play(t_data2 *data)
{
	draw_pov(data);
	data->old_time = data->time;
	data->time = clock();
	data->frame_time = (data->time - data->old_time) / 1000.0;
	data->move_speed = 1 * 0.2;
	data->rot_speed = 1 * 0.2;
}

int	ft_move(int keysym, t_data2 *data)
{
	if (keysym == ESCAPE)
		end_process(data);
	else if (keysym == W_KEY)
	{
		if (world_map[(int)(data->pos_x + data->dir_x * data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x += data->dir_x * data->move_speed;
		if (world_map[(int)(data->pos_x)][(int)(data->pos_y + data->dir_y * data->move_speed)] == 0)
			data->pos_y += data->dir_y * data->move_speed;
	}
	else if (keysym == S_KEY)
	{
		if (world_map[(int)(data->pos_x - data->dir_x * data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x -= data->dir_x * data->move_speed;
		if (world_map[(int)(data->pos_x)][(int)(data->pos_y - data->dir_y * data->move_speed)] == 0)
			data->pos_y -= data->dir_y * data->move_speed;		
	}
	else if (keysym == A_KEY)
	{
		if (world_map[(int)(data->pos_x - data->dir_x * data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x -= data->dir_x * data->move_speed;
		if (world_map[(int)(data->pos_x)][(int)(data->pos_y + data->dir_y * data->move_speed)] == 0)
			data->pos_y += data->dir_y * data->move_speed;			
	}
	else if (keysym == D_KEY)
	{
		if (world_map[(int)(data->pos_x + data->dir_x * data->move_speed)][(int)(data->pos_y)] == 0)
			data->pos_x += data->dir_x * data->move_speed;
		if (world_map[(int)(data->pos_x)][(int)(data->pos_y - data->dir_y * data->move_speed)] == 0)
			data->pos_y -= data->dir_y * data->move_speed;			
	}
	else if (keysym == LEFT_ARROW)
	{
		data->old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-data->rot_speed) - data->dir_y * sin(-data->rot_speed);
		data->dir_y = data->old_dir_x * sin(-data->rot_speed) + data->dir_y * cos(-data->rot_speed);
		data->old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-data->rot_speed) - data->plane_y * sin(-data->rot_speed);
		data->plane_y = data->old_plane_x * sin(-data->rot_speed) + data->plane_y * cos(-data->rot_speed);
	}
	else if (keysym == RIGTH_ARROW)
	{
		data->old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(data->rot_speed) - data->dir_y * sin(data->rot_speed);
		data->dir_y = data->old_dir_x * sin(data->rot_speed) + data->dir_y * cos(data->rot_speed);
		data->old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(data->rot_speed) - data->plane_y * sin(data->rot_speed);
		data->plane_y = data->old_plane_x * sin(data->rot_speed) + data->plane_y * cos(data->rot_speed);		
	}
	play(data);
	return (Success);
}

int	main()
{
	t_data2	data;

	data = get_init_data();
	if (data.mlx == NULL || data.win == NULL)
	{
		exit(1);
	}
	play(&data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &ft_move, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
		&end_process, &data);
	mlx_loop(data.mlx);
}