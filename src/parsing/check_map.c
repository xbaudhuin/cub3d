/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:33:28 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/08 17:24:16 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		return (FALSE);
	len_previous = ft_strlen(previous_line);
	len_next = ft_strlen(next_line);
	if (i >= len_previous || i >= len_next || i == 0)
		return (FALSE);
	if (is_map_char(line[i - 1]) == FALSE)
		return (FALSE);
	if (is_map_char(line[i + 1]) == FALSE)
		return (FALSE);
	if (is_map_char(previous_line[i]) == FALSE)
		return (FALSE);
	if (is_map_char(next_line[i]) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	is_valid_line_map(t_vector *vector, int index, int *player_flag)
{
	unsigned int	i;
	char			*line;

	i = 0;
	line = vector_get(vector, index);
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
			if (is_closed(vector, line, i, index) != TRUE)
				return (UNCLOSED_MAP);
			i++;
		}
		else
			return (INVALID_CHAR);
	}
	return (SUCCESS);
}

int	check_map(t_vector *vector)
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
