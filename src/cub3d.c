#include "cub3d.h"

t_data_exec	get_init_data(char *path)
{
	t_data_exec		data;
	t_start_coord	start;

	ft_bzero(&data, sizeof(data));
	data.dir_x = -1;
	data.dir_y = 0;
	data.plane_x = 0;
	data.plane_y = 0.66;
	data.mlx = mlx_init();
	if (data.mlx != NULL)
	{
		data.win = mlx_new_window(data.mlx, WIDTH,
			HEIGHT, "raycasting_test");
	}
	data.file = open_map(path);
	if (data.file == NULL ||  data.file->map == NULL)
	{
		printf("map null\n");
		exit(1);	
	}
	start = get_start_coord(data.file->map);
	data.pos_x = start.x;
	data.pos_y = start.y;
	starting_rotate(&data, start.direction);
	return (data);
}

int	main(int ac, char **av)
{
	t_data_exec	data;

	(void)ac;
	data = get_init_data(av[1]);
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