/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoyen-- <ldoyen--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:49:15 by ldoyen--          #+#    #+#             */
/*   Updated: 2024/04/09 14:41:16 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"
# include <unistd.h>

# define MOUSE_LIMIT 10

# define NB_DOOR_TXT 6

# define DOOR_1_PATH "./textures/doors_xpm_128/door_1.xpm"
# define DOOR_2_PATH "./textures/doors_xpm_128/door_2.xpm"
# define DOOR_3_PATH "./textures/doors_xpm_128/door_3.xpm"
# define DOOR_4_PATH "./textures/doors_xpm_128/door_4.xpm"
# define DOOR_5_PATH "./textures/doors_xpm_128/door_5.xpm"
# define DOOR_6_PATH "./textures/doors_xpm_128/door_6.xpm"

int		mouse_rotate(int x, int y, t_data_exec *data);
t_img	*get_door_txt(t_data_exec *data);
void	free_door(t_img **door_txt, t_data_exec *data);
void	check_door(t_data_exec *data);

#endif
