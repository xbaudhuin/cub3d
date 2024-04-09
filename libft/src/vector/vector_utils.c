/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:35:30 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/04/09 13:20:30 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

t_vector	*vector_init(void)
{
	t_vector	*vector;

	vector = malloc(sizeof(*vector));
	if (vector == NULL)
		return (NULL);
	vector->current_size = 0;
	vector->size_max = 4;
	vector->array = ft_calloc(sizeof(char *), vector->size_max);
	if (vector->array == NULL)
	{
		free(vector);
		vector = NULL;
	}
	return (vector);
}

int	vector_current_size(t_vector *vector)
{
	return ((int)vector->current_size);
}

void	vector_set(t_vector *vector, size_t index, char *str)
{
	if (index < (vector->current_size - 1))
	{
		free(vector->array[index]);
		vector->array[index] = str;
	}
}

char	*vector_get(t_vector *vector, size_t index)
{
	if (index < (vector->current_size - 1))
		return (vector->array[index]);
	return (NULL);
}

void	free_vector(t_vector *vector)
{
	size_t	i;

	i = 0;
	while (i < vector->current_size)
	{
		free(vector->array[i]);
		vector->array[i] = NULL;
		i++;
	}
	free(vector->array);
	vector->array = NULL;
	free(vector);
}
