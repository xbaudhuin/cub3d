/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:10:41 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/03/29 17:57:14 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef struct s_vector
{
	char	**array;
	size_t	size_max;
	size_t	current_size;
}				t_vector;

t_vector	*vector_init(void);
int			vector_current_size(t_vector *vector);
void		vector_add(t_vector *vector, char *str);
void		vector_set(t_vector *vector, size_t index, char *str);
char		*vector_get(t_vector *vector, size_t index);
void		vector_del_one(t_vector *vector, size_t index);
void		free_vector(t_vector *vector);

#endif
