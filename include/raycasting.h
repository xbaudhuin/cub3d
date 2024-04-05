/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:58:48 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/04 16:58:49 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define X 1
# define Y 2

# define WIDTH 1780
# define HEIGHT 960

void	do_dda(t_data_exec *data);
void	calculate_delta(t_data_exec *data);
void	calculate_step(t_data_exec *data);
double	calculate_perp_wall_dist(t_data_exec *data);
double	get_hit_pos(t_data_exec *data, double perp_wall_dist);
int		hit_dir(t_data_exec *data);
int		get_texture_x(t_data_exec *data);

#endif
