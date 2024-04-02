/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:05:05 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 18:32:38 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	skip_spaces(const char *line)
{
	unsigned int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

unsigned int	skip_space_digit(const char *line)
{
	unsigned int	i;

	i = 0;
	while (ft_isdigit(line[i]) == TRUE)
		i++;
	i += skip_spaces(&line[i]);
	return (i);
}

 int	atoi_color(const char *line, int *error)
{
	int	color;

	color = ft_atoi(line, error);
	if (*error == TRUE || color > 255 || color < 0)
		*error = TRUE;
	return (color);
}

char	*skip_empty_line(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, "\n", 2) != 0)
			break ;
		free(line);
	}
	return (line);
}
