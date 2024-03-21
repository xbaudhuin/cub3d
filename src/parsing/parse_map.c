/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:12:32 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/03/21 19:38:22 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "libft.h"
#include "unistd.h"
#include <fcntl.h>

static int	check_filename(const char *str, const char *filename)
{
	if (str == NULL || str == filename)
		return (FALSE);
	if (ft_strncmp(str, ".cub", 5) != 0)
		return (FALSE);
}

char	**open_map(char *filename)
{
	char	*str;
	int		fd;

	if (check_filename(ft_strrchr(filename, '.') == FALSE))
		return (ft_fprintf(2, RED"Error: "RESET"invalid map extension: %s", filename), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror(RED"open_map: ")NULL);

}
