/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:12:32 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/08 14:13:55 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "libft.h"
#include "structures.h"
#include "vector.h"
#include <stdio.h>
#include <unistd.h>

static int	check_filename(const char *str, const char *filename)
{
	if (str == NULL || str == filename)
		return (FALSE);
	if (filename[str - filename - 1] == '/')
		return (FALSE);
	if (ft_strncmp(str, ".cub", 5) != 0)
		return (FALSE);
	return (TRUE);
}

static t_texture **init_texture(void)
{
	unsigned int	i;
	t_texture		**texture;

	i = 0;
	texture = ft_calloc(sizeof(t_texture *), NB_TEXTURE + 1);
	if (texture == NULL)
		return (NULL);
	while (i < NB_TEXTURE)
	{
		texture[i] = ft_calloc(sizeof(t_texture), 1);
		if (texture[i] == NULL)
			return (free_texture(texture, NULL), NULL);
		texture[i]->img = ft_calloc(sizeof(t_img), 1);
		if (texture[i]->img == NULL)
			return (free_texture(texture, NULL), NULL);
		i++;
	}
	return (texture);
}

static void	get_texture(int fd, t_data **data, void *mlx_ptr)
{
	char			*line;
	unsigned int	i;

	i = 0;
	(*data)->texture = init_texture();
	if ((*data)->texture == NULL)
	{
		perror(RED"In init_texture"RESET);
		return ;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (check_current_line(line, &i, data) == FALSE)
		{
			free_texture((*data)->texture, NULL);
			(*data)->texture = NULL;
			return (free(line));
		}
		free(line);
		if (i == 63)
			break ;
	}
	(*data)->texture = get_texture_img_from_xpm((*data)->texture, mlx_ptr);
}

t_data	*open_map(char *filename, void *mlx_ptr)
{
	int			fd;
	t_data		*data;

	data = ft_calloc(sizeof(*data), 1);
	if (data == NULL)
		return (perror(RED"In open_map"RESET), NULL);
	if (filename == NULL
		|| check_filename(ft_strrchr(filename, '.'), filename) == FALSE)
		return (ft_fprintf(STDERR_FILENO, RED"Error\n"RESET
				"invalid map extension: %s\n", filename), free(data), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror(RED"open_map"RESET), close(fd), free(data), NULL);
	get_texture(fd, &data, mlx_ptr);
	if (data->texture == NULL)
		return (close(fd), free_data(data, mlx_ptr), NULL);
	data->map = parse_map(fd);
	if (data->map == NULL)
		return (free_data(data, mlx_ptr), close(fd), NULL);
	print_data(data);
	close(fd);
	return (data);
}
