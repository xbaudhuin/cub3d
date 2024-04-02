/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:28:32 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 18:33:55 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "vector.h"
#include <unistd.h>

static void	fill_vector(t_vector *vector, char *line, int fd)
{
	while (line)
	{
		vector_add(vector, line);
		line = get_next_line(fd);
	}
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
	fill_vector(vector, line, fd);
	if (check_map(vector) == FAILURE)
		return (free_vector(vector), NULL);
	array = vector->array;
	free(vector);
	return (array);
}
