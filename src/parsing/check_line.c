/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:25:03 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 18:26:37 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	check_current_line(const char *line,
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