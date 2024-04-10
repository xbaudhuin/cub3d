/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movement.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:07:11 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/04 17:07:13 by ldoyen--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_MOVEMENT_H
# define CAMERA_MOVEMENT_H

# define ESCAPE 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_ARROW 65361
# define RIGTH_ARROW 65363

# define VOID 48
# define WALL 49
# define OPEN_DOOR 50
# define CLOSE_DOOR 51

# define M_PI   3.14159265358979323846
# define M_PI_2   1.57079632679489661923
# define M_PI_4   0.78539816339744830962

# define ROTATE_SPEED 0.05
# define MOVE_SPEED 0.2

void	move(int keysim, t_data_exec *data);
int		read_key(int keysym, t_data_exec *data);
void	rotate(int keysim, t_data_exec *data);
void	starting_rotate(t_data_exec *data, int orientation);
int		is_walkable(char c);

#endif
