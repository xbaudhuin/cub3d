/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:31:43 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/08 17:29:24 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
