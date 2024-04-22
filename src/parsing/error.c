/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:31:43 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/22 12:25:16 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include <unistd.h>

void	ft_parse_map_error(int error)
{
	ft_fprintf(STDERR_FILENO, RED"Error\n"RESET);
	if (error == INVALID_PLAYER)
		ft_fprintf(STDERR_FILENO, "Incorrect player start position\n");
	if (error == INVALID_TEXTURE)
		ft_fprintf(STDERR_FILENO, "Incorrect texture\n");
	if (error == INVALID_COLOR)
		ft_fprintf(STDERR_FILENO, "Incorrect color\n");
	if (error == UNCLOSED_MAP)
		ft_fprintf(STDERR_FILENO, "Invalid map\n");
	if (error == INVALID_CHAR)
		ft_fprintf(STDERR_FILENO, "Invalid map\n");
}

int	print_error(const char *line)
{
	ft_fprintf(STDERR_FILENO, RED"Error\n"RESET
		"Invalid RGB color: %s", line);
	return (TRUE);
}

static int	is_invalid_first_char(const char *line)
{
	if (ft_strncmp(line, "C ", 2) != 0 && ft_strncmp(line, "F ", 2) != 0
		&& ft_strncmp(line, "NO ", 3) != 0 && ft_strncmp(line, "WE ", 3) != 0
		&& ft_strncmp(line, "EA ", 3) != 0 && ft_strncmp(line, "SO ", 3) != 0)
		return (TRUE);
	return (FALSE);
}

static int	error_line_texture(const char *line, int *player_flag)
{
	unsigned int	i;

	i = 0;
	if (is_invalid_first_char(line) == TRUE)
		return (INVALID_CHAR);
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '1')
			i++;
		else if (is_map_char(line[i]) == TRUE)
		{
			if (is_player_char(line[i]) == TRUE)
			{
				*player_flag += 1;
				if (*player_flag > 1)
					return (INVALID_PLAYER);
			}
			i++;
		}
		else
			return (INVALID_CHAR);
	}
	return (SUCCESS);
}

int	print_texture_error(unsigned int *mask, const char *line)
{
	int	player_flag;

	player_flag = 0;
	ft_fprintf(STDERR_FILENO, RED"Error\n"RESET);
	if (error_line_texture(line, &player_flag) == SUCCESS && *mask != 63)
		ft_fprintf(STDERR_FILENO, "Missing elements\n");
	else
		ft_fprintf(STDERR_FILENO, "Invalid line: %s\n", line);
	return (FALSE);
}
