/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:12:32 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/01 18:48:58 by xabaudhu         ###   ########.fr       */
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

static unsigned int	skip_spaces(const char *line)
{
	unsigned int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

static int	atoi_color(const char *line, int *error)
{
	int	color;

	color = ft_atoi(line, error);
	if (*error == TRUE || color > 255 || color < 0)
		*error = TRUE;
	return (color);
}

static int	shift_color(int rgb_color, int color, int bit_shift)
{
	return ((rgb_color << bit_shift) | color);
}

static int	print_error(const char *line)
{
	ft_fprintf(STDERR_FILENO, RED"Error\n"RESET
		"Invalid RGB color: %s", line);
	return (TRUE);
}

static int	skip_space_digit(const char *line)
{
	unsigned int	i;

	i = 0;
	while (ft_isdigit(line[i]) == TRUE)
		i++;
	i += skip_spaces(&line[i]);
	return (i);
}

static int	get_color_from_file(const char *line, int *error, int bit_shift)
{
	unsigned int	i;
	int				rgb;
	int				count;

	rgb = 0;
	count = 0;
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		i += skip_spaces(&line[i]);
		rgb = shift_color(rgb, atoi_color(&line[i], error), bit_shift);
		if (*error == TRUE)
			break ;
		bit_shift = 8;
		i += skip_space_digit(&line[i]);
		if ((line[i] != ',' && line[i] != '\n') || count > 2)
			break ;
		count++;
		i++;
	}
	if (*error == TRUE || count != 3)
		*error = print_error(line);
	return (rgb);
}

static char	*ft_strdup_texture(const char *line, int *error)
{
	char			*dup;

	dup = ft_strtrim(line, " \n");
	if (dup == NULL)
	{
		perror(RED"Error\n"RESET);
		*error = TRUE;
		return (NULL);
	}
	return (dup);
}

static void	free_texture(t_texture *texture)
{
	if (texture == NULL)
		return ;
	if (texture->NO != NULL)
		free(texture->NO);
	if (texture->EA != NULL)
		free(texture->EA);
	if (texture->WE != NULL)
		free(texture->WE);
	if (texture->SO != NULL)
		free(texture->SO);
	free(texture);
}

static void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->texture != NULL)
		free_texture(data->texture);
	data->texture = NULL;
	if (data->map != NULL)
		free_vector(data->map);
	data->map = NULL;
	free(data);
}

static int	check_double(
		unsigned int *i, unsigned int mask, const char *error_message)
{
	if ((*i & mask) != 0)
	{
		ft_fprintf(STDERR_FILENO, RED"Error\n"RESET"%s\n", error_message);
		return (FALSE);
	}
	*i = *i | mask;
	return (TRUE);
}

static int	check_line_color(
			const char *line, unsigned int *i, t_texture *texture, int *error)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (check_double(i, 1, "floor color already assigned") == FALSE)
			return (FALSE);
		texture->color_floor = get_color_from_file(&line[2], error, 0);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (check_double(i, 2, "ceiling color already assigned") == FALSE)
			return (FALSE);
		texture->color_ceiling = get_color_from_file(&line[2], error, 0);
	}
	return (TRUE);
}

static int	check_line_texture(const char *line,
				unsigned int *i, t_texture *texture, int *error)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (check_double(i, 4, "North texture already assigned") == FALSE)
			return (FALSE);
		texture->NO = ft_strdup_texture(&line[3], error);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (check_double(i, 8, "South texture already assigned") == FALSE)
			return (FALSE);
		texture->SO = ft_strdup_texture(&line[3], error);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (check_double(i, 16, "West texture already assigned") == FALSE)
			return (FALSE);
		texture->WE = ft_strdup_texture(&line[3], error);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (check_double(i, 32, "East texture already assigned") == FALSE)
			return (FALSE);
		texture->EA = ft_strdup_texture(&line[3], error);
	}
	return (TRUE);
}

static int	check_current_line(const char *line,
				unsigned int *i, t_texture *texture)
{
	int	error;

	error = FALSE;
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		check_line_color(line, i, texture, &error);
	else if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		check_line_texture(line, i, texture, &error);
	else if (ft_strncmp(line, "\n", 2) == 0)
		return (TRUE);
	else
	{
		ft_fprintf(STDERR_FILENO, RED"Error\n"RESET"invalid line: %s", line);
		return (FALSE);
	}
	if (error == TRUE)
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

static	void	print_texture(t_texture *texture)
{
	if (texture == NULL)
		return ;
	ft_printf(BLU"texture->NO ="RESET" %s\n", texture->NO);
	ft_printf(BLU"texture->SO ="RESET" %s\n", texture->SO);
	ft_printf(BLU"texture->NO ="RESET" %s\n", texture->WE);
	ft_printf(BLU"texture->NO ="RESET" %s\n", texture->EA);
	ft_printf(BLU"texture->color_ceiling ="RESET" %d\n", texture->color_ceiling);
	ft_printf(BLU"texture->color_floor ="RESET" %d\n", texture->color_floor);
}

static void	print_map(t_vector *vector)
{
	unsigned int	i;

	i = 0;
	if (vector == NULL)
	{
		ft_printf(RED"NO MAP\n"RESET);
		return ;
	}
	ft_printf(YEL"\n\n\nMAP\n\n\n"RESET);
	while (i < (unsigned int)vector_current_size(vector))
	{
		ft_printf("%s", vector_get(vector, i));
		i++;
	}
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
	print_texture(data->texture);
	if (data->texture == NULL)
		return (close(fd), NULL);
	data->map = parse_map(fd);
	print_map(data->map);
	free_data(data);
	close(fd);
	return (data);
}

int	main(int ac, char **av)
{
	(void)ac;
	open_map(av[1]);
	return (0);
}
