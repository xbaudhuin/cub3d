/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:28:32 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:11 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "vector.h"
#include <unistd.h>

static t_vector	*fill_vector(t_vector *vector, char *line, int fd)
{
	while (line)
	{
		vector = vector_add(vector, line);
		if (vector == NULL)
			return (free(line), NULL);
		line = get_next_line(fd);
	}
	return (vector);
}

char	**parse_map(int fd)
{
	char		*line;
	t_vector	*vector;
	char		**array;

	line = skip_empty_line(fd);
	if (line == NULL)
	{
		ft_fprintf(2, RED"Error\n"RESET"Empty map\n");
		return (NULL);
	}
	vector = vector_init();
	if (vector == NULL)
	{
		perror(RED"Error\n"RESET"Fail vector initialization");
		return (NULL);
	}
	vector = fill_vector(vector, line, fd);
	if (vector == NULL)
		return (NULL);
	if (check_map(vector) == FAILURE)
		return (free_vector(vector), NULL);
	array = vector->array;
	free(vector);
	return (array);
}
