/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:31:43 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/13 13:53:16 by xabaudhu         ###   ########.fr       */
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

static int	error_line_map(const char *line, int *player_flag)
{
	unsigned int	i;

	i = 0;
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
	if (error_line_map(line, &player_flag) == SUCCESS && *mask != 63)
		ft_fprintf(STDERR_FILENO, "Missing elements\n");
	else
		ft_fprintf(STDERR_FILENO, "Invalid line: %s\n", line);
	return (FALSE);
}
