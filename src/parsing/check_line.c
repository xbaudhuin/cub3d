/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:25:03 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/13 13:50:56 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strdup_texture(const char *line, int *error)
{
	char	*dup;

	dup = ft_strtrim(line, " \n");
	if (dup == NULL)
	{
		perror(RED"Error\n"RESET);
		*error = TRUE;
		return (NULL);
	}
	return (dup);
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
			const char *line, unsigned int *i, t_data **data, int *error)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (check_double(i, 1, "floor color already assigned") == FALSE)
			return (FALSE);
		(*data)->color_floor = get_color_from_file(&line[2], error, 0);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (check_double(i, 2, "ceiling color already assigned") == FALSE)
			return (FALSE);
		(*data)->color_ceiling = get_color_from_file(&line[2], error, 0);
	}
	return (TRUE);
}

static int	check_line_texture(const char *line,
				unsigned int *i, t_texture **texture, int *error)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (check_double(i, 4, "North texture already assigned") == FALSE)
			return (FALSE);
		texture[NORTH]->path = ft_strdup_texture(&line[3], error);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (check_double(i, 8, "South texture already assigned") == FALSE)
			return (FALSE);
		texture[SOUTH]->path = ft_strdup_texture(&line[3], error);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (check_double(i, 16, "West texture already assigned") == FALSE)
			return (FALSE);
		texture[WEST]->path = ft_strdup_texture(&line[3], error);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (check_double(i, 32, "East texture already assigned") == FALSE)
			return (FALSE);
		texture[EAST]->path = ft_strdup_texture(&line[3], error);
	}
	return (TRUE);
}

int	check_current_line(const char *line,
				unsigned int *i, t_data **data)
{
	int	error;

	error = FALSE;
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		check_line_color(line, i, data, &error);
	else if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		check_line_texture(line, i, (*data)->texture, &error);
	else if (ft_strncmp(line, "\n", 2) == 0)
		return (TRUE);
	else
	{
		return (print_texture_error(i, line));
	}
	if (error == TRUE)
		return (FALSE);
	return (TRUE);
}
