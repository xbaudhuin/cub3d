/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_get_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:22:13 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 18:23:17 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	shift_color(int rgb_color, int color, int bit_shift)
{
	return ((rgb_color << bit_shift) | color);
}

int	get_color_from_file(const char *line, int *error, int bit_shift)
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
