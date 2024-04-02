#include "cub3d.h"

int world_map[MAP_HEIGHT][MAP_WIDTH]=
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

t_data_exec	get_init_data(void)
{
	t_data_exec	data;

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

int	end_process(t_data_exec *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	calculate_delta(t_data_exec *data)
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

void	calculate_step(t_data_exec *data)
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

void	draw_pov(t_data_exec *data)
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
			case 1:  color = 0xFFFFFF;  break; //red
			case 2:  color = 0xFF00FF;  break; //green
			case 3:  color = 0x0000FF;   break; //blue
			case 4:  color = 0x00FFFF;  break; //white
			default: color = 0xFFFF00; break; //yellow
		} 
		draw_line_on_img(img, x, data->draw_start, x, data->draw_end, color);
	}
	mlx_put_image_to_window(data->mlx, data->win, img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx, img.mlx_img);
}

int	main()
{
	t_data_exec	data;

	data = get_init_data();
	if (data.mlx == NULL || data.win == NULL)
	{
		exit(1);
	}
	draw_pov(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &read_key, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
		&end_process, &data);
	mlx_loop(data.mlx);
}
