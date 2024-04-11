/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:09:11 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/11 19:00:51 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <stdio.h>

static char	**ft_realloc(t_vector *vector, size_t new_size)
{
	char	**new_array;
	size_t	i;

	new_array = ft_calloc(sizeof(*new_array), new_size + 1);
	if (new_array == NULL)
		return (NULL);
	i = 0;
	while (i < vector->current_size)
	{
		new_array[i] = vector->array[i];
		i++;
	}
	free(vector->array);
	vector->array = NULL;
	return (new_array);
}

static t_vector *vector_resize(t_vector *vector, int size)
{
	char	**new_array;

	new_array = ft_realloc(vector, sizeof(char *) * size);
	if (new_array == NULL)
	{
		return (free_vector(vector), NULL);
	}
	else
		vector->size_max = size;
	vector->array = new_array;
	return (vector);
}

t_vector	*vector_add(t_vector *vector, char *str)
{
	if (vector->current_size == vector->size_max)
		vector = vector_resize(vector, vector->size_max * 2);
	if (vector == NULL)
		return (NULL);
	vector->array[vector->current_size] = str;
	vector->current_size += 1;
	return (vector);
}

void	vector_del_one(t_vector *vector, size_t index)
{
	size_t	i;

	i = index;
	if (index >= vector->current_size)
		return ;
	free(vector->array[index]);
	vector->array[index] = NULL;
	while (i < vector->current_size)
	{
		vector->array[i] = vector->array[i + 1];
		i++;
	}
	vector->current_size -= 1;
	if (vector->current_size > 0
		&& vector->current_size * 4 <= vector->size_max)
		vector_resize(vector, vector->size_max / 2);
}
