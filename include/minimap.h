/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:16:57 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/11 18:52:29 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

void	get_minimap(t_data_exec *data, t_img *img);
void	hightlight_minimap(t_img *img);
int		is_player(t_data_exec *data, int x, int y);
int		get_color_for_block(const char c);

#endif
