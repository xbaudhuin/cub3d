/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:28:32 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/02 17:26:34 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "vector.h"
#include <unistd.h>

static char	*skip_empty_line(int fd)
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

static int	is_player_char(const char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (TRUE);
	return (FALSE);
}

static int	is_map_char(const char c)
{
	if (c == '0' || c == '1')
		return (TRUE);
	if (is_player_char(c) == TRUE)
		return (TRUE);
	return (FALSE);
}

static int	is_closed(
	t_vector *vector, const char *line, unsigned int i, int index)
{
	char			*previous_line;
	char			*next_line;
	unsigned int	len_previous;
	unsigned int	len_next;

	if (index == 0 || index == vector_current_size(vector) - 1)
		return (FALSE);
	previous_line = vector_get(vector, index - 1);
	next_line = vector_get(vector, index + 1);
	if (previous_line == NULL || next_line == NULL)
		printf(RED"\nprevious_line == NULL || next_line == NULL\n");
	len_previous = ft_strlen(previous_line);
	len_next = ft_strlen(next_line);
	if (i >= len_previous || i >= len_next)
		return (FALSE);
	if (is_map_char(line[i - 1]) == FALSE)
		printf(RED"\nis_map_char(line[i - 1]): (%c)\n"RESET, line[i - 1]);
	if (is_map_char(line[i + 1]) == FALSE)
		printf(RED"\nis_map_char(line[i + 1]): (%c)\n"RESET, line[i + 1]);
	if (is_map_char(previous_line[i]) == FALSE)
		return (FALSE);
	if (is_map_char(next_line[i]) == FALSE)
		return (FALSE);
	return (TRUE);
}

static void	ft_parse_map_error(int error)
{
	ft_fprintf(STDERR_FILENO, RED"Error\n"RESET);
	if (error == INVALID_PLAYER)
		ft_fprintf(STDERR_FILENO, "Incorrect player start position\n");
	if (error == INVALID_TEXTURE)
		ft_fprintf(STDERR_FILENO, "Incorrect texture\n");
	if (error == INVALID_COLOR)
		ft_fprintf(STDERR_FILENO, "Incorrect color\n");
	if (error == UNCLOSED_MAP)
		ft_fprintf(STDERR_FILENO, "Unclosed map\n");
}

static int	is_valid_line_map(t_vector *vector, int index, int *player_flag)
{
	unsigned int	i;
	char			*line;

	i = 0;
	line = vector_get(vector, index);
	while (line[i] != '\n')
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
			if (is_closed(vector, line, i, index) == FALSE)
				return (UNCLOSED_MAP);
			i++;
		}
		else
			return (INVALID_CHAR);
	}
	return (SUCCESS);
}

static int	check_map(t_vector *vector)
{
	int	player_flag;
	int	error;
	int	i;

	player_flag = 0;
	i = 0;
	while (vector_get(vector, i) != NULL)
	{
		error = is_valid_line_map(vector, i, &player_flag);
		if (error != SUCCESS)
		{
			ft_parse_map_error(error);
			return (FAILURE);
		}
		i++;
	}
	if (player_flag != 1)
	{
		ft_parse_map_error(INVALID_PLAYER);
		return (FAILURE);
	}
	return (SUCCESS);
}

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
