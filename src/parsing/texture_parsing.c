/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:12:32 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 18:42:10 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "libft.h"
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

static t_texture	*get_texture(int fd)
{
	char			*line;
	unsigned int	i;
	t_texture		*texture;

	i = 0;
	texture = ft_calloc(sizeof(*texture), 1);
	if (texture == NULL)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (check_current_line(line, &i, texture) == FALSE)
			return (free(line), free_texture(texture), NULL);
		free(line);
		if (i == 63)
			break ;
	}
	return (texture);
}

t_data	*open_map(char *filename)
{
	int			fd;
	t_data		*data;

	data = ft_calloc(sizeof(*data), 1);
	if (data == NULL)
		return (NULL);
	if (filename == NULL
		|| check_filename(ft_strrchr(filename, '.'), filename) == FALSE)
		return (ft_fprintf(STDERR_FILENO, RED"Error\n"RESET
				"invalid map extension: %s\n", filename), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror(RED"open_map: "RESET""), NULL);
	data->texture = get_texture(fd);
	if (data->texture == NULL)
		return (close(fd), free_data(data), NULL);
	data->map = parse_map(fd);
	print_data(data);
	free_data(data);
	close(fd);
	return (data);
}
 int main(int ac, char **av)
{
	if (ac != 2)
		return (ft_printf(RED"Error\n""only 1 argument(path to the map) is required\n"));
	open_map(av[1]);
	return (0);
}
