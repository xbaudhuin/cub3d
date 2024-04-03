#include "cub3d.h"

t_data_exec	get_init_data(char *path)
{
	t_data_exec	data;

	ft_bzero(&data, sizeof(data));
	data.pos_x = 2;
	data.pos_y = 3;
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
	data.parse_data = open_map(path);
	if (data.parse_data == NULL ||  data.parse_data->map == NULL)
	{
		printf("map null\n");
		exit(1);	
	}
	data.parse_data->map[1][1] = '0';
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