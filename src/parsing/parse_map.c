/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:28:32 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/03/29 18:27:20 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"
#include "vector.h"

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

static int	is_valid_char(const char c, int *player_flag)
{
	if (c == '0' || c == '1' || c == ' ')
		return (TRUE);
	if (c == 'N' || c =='S' || c == 'E' || c == 'W')
	{
		if (*player_flag == 0)
		{
			*player_flag = 1;
			return (TRUE);
		}
		*player_flag = 2;
	}
	return (FALSE);
}

static int	fill_vector(t_vector *vector, char *line, int fd)
{
	int				player_flag;
	unsigned int	i;

	player_flag = 0;
	while (line)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
		{

		}
		
	}

}

t_vector	*parse_map(int fd)
{
	char	*line;
	t_vector	*vector;

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
	if (fill_vector(vector, line, fd) == FAILURE)
		return (free_vector(vector), NULL);
	return (vector);
}
