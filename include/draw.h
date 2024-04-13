/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:04:12 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/04 17:04:12 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define TXT_SIZE 64

void	draw_ceiling(t_img img, int color);
void	draw_floor(t_img img, int color);
void	put_pixel_on_img(t_img img, int x, int y, int color);
void	draw_pov(t_data_exec *data);
void	draw_wall_line(t_img img, int x, double perp_wall_dist,
			t_data_exec *data);

#endif
