/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:12:32 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/03/23 19:22:55 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "libft.h"
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

static int	ft_atoi_color(const char *line, int *error)
{
	int	color;

	color = ft_atoi(line, error);
	if (*error == TRUE || color > 255 || color < 0)
	{
		ft_fprintf(STDERR_FILENO, RED"Error\n"RESET
			"Error during parsing: '%s' doesnt fit inside a char\n", line);
		*error = TRUE;
	}
	return (color);
}

static int	combine_rgb_color(int rgb_color, int color, int bit_shift)
{
	return ((rgb_color << bit_shift) | color);
}

static int	get_color_from_file(char *line, int *error)
{
	unsigned int	i;
	int				rgb_color;
	int				bit_shift;
	int				count;

	bit_shift = 0;
	rgb_color = 0;
	count = 0;
	i = skip_spaces(line);
	while (line[i] != '\0' && line[i] != '\n')
	{
		rgb_color = combine_rgb_color(
				rgb_color, ft_atoi_color(&line[i], error), bit_shift);
		if (*error == TRUE)
			break ;
		bit_shift = 8;
		while (ft_isdigit(line[i]) == TRUE)
			i++;
		if ((line[i] != ',' && line[i] != '\n') || count > 2)
		{
			ft_fprintf(STDERR_FILENO, RED"Error\n"RESET
				"error during parsing: %s", &line[i]);
			*error = TRUE;
			break ;
		}
		count++;
		i++;
	}
	if (count != 3)
	{
		ft_fprintf(STDERR_FILENO, RED"Error\n"RESET
			"error during parsing: %s", line);
		*error = TRUE;
	}
	return (rgb_color);
}

static char	*ft_strdup_texture(const char *line, int *error)
{
	char			*dup;
	unsigned int	len;

	len = ft_strlen(line) - 1;
	dup = malloc(sizeof(*dup) * (len + 1));
	if (dup == NULL)
	{
		perror(RED"Error\n"RESET"error in ft_strdup_texture");
		*error = TRUE;
		return (NULL);
	}
	ft_memmove(dup, line, len);
	dup[len] = '\0';
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

static int	check_current_line(char *line, unsigned int *i, t_texture *texture)
{
	int	error;

	error = FALSE;
	if (ft_strncmp(line, "F ", 2) == 0)
		texture->color_floor = get_color_from_file(&line[2], &error);
	else if (ft_strncmp(line, "C ", 2) == 0)
		texture->color_ceiling = get_color_from_file(&line[2], &error);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		texture->NO = ft_strdup_texture(&line[3], &error);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		texture->SO = ft_strdup_texture(&line[3], &error);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		texture->WE = ft_strdup_texture(&line[3], &error);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		texture->EA = ft_strdup_texture(&line[3], &error);
	else if (ft_strncmp(line, "\n", 2) == 0)
		return (TRUE);
	else
		return (FALSE);
	*i += 1;
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
		if (i == 6)
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

t_data	*open_map(char *filename)
{
	int			fd;
	t_data		*data;
	t_texture	*texture;

	data = NULL;
	if (check_filename(ft_strrchr(filename, '.'), filename) == FALSE)
		return (ft_fprintf(STDERR_FILENO, RED"Error: "RESET
				"invalid map extension: %s\n", filename), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror(RED"open_map: "RESET""), NULL);
	texture = get_texture(fd);
	print_texture(texture);
	free_texture(texture);
	close(fd);
	return (data);
}

int	main(int ac, char **av)
{
	(void)ac;
	open_map(av[1]);
	return (0);
}
