/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:14:29 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/08 17:16:22 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_data	*open_map(char *filename, void *mlx_ptr);
int		get_color_from_file(const char *line, int *error, int bit_shift);
void	print_data(t_data *data);
char	**parse_map(int fd);
int		check_map(t_vector *vector);
int		check_current_line(const char *line,
				unsigned int *i, t_data **data);
t_texture	**get_texture_img_from_xpm(t_texture **texture, void *mlx_ptr);

//IS CHAR

int				is_player_char(const char c);
int				is_map_char(const char c);
// PARSING_UTILS

unsigned int	skip_spaces(const char *line);
unsigned int	skip_space_digit(const char *line);
int				atoi_color(const char *line, int *error);
int				print_error(const char *line);
void			ft_parse_map_error(int error);
char			*skip_empty_line(int fd);
t_start_coord	get_start_coord(char **map);
//FREE FUNCTION

void	free_data(t_data *data, void *mlx_ptr);
void	free_texture(t_texture **texture, void *mlx_ptr);

#endif
