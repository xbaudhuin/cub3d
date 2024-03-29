/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xabaudhu <xabaudhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:08:09 by xabaudhu          #+#    #+#             */
/*   Updated: 2024/03/29 17:55:08 by xabaudhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	is_white_space(const char c)
{
	if (c >= 9 && c <= 13)
		return (TRUE);
	else if (c == 32)
		return (TRUE);
	return (FALSE);
}

static unsigned int	trim_white_space(const char *nptr)
{
	unsigned int	i;

	i = 0;
	while (is_white_space(nptr[i]) == TRUE)
		i++;
	return (i);
}

static int	if_sign(const char c, int *sign)
{
	if (c == '+')
	{
		return (TRUE);
	}
	if (c == '-')
	{
		*sign = -1;
		return (TRUE);
	}
	return (FALSE);
}

static int	get_res(const char *nptr, int *error)
{
	long int		res;
	unsigned int	i;

	i = 0;
	res = 0;
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]) == TRUE)
	{
		if (i > 10)
		{
			*error = 1;
			break ;
		}
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (res > INT_MAX || res < INT_MIN)
		*error = 1;
	return (res);
}

int	ft_atoi(const char *nptr, int *error)
{
	size_t			i;
	int				sign;

	sign = 1;
	i = trim_white_space(nptr);
	if (if_sign(nptr[i], &sign) == TRUE)
		i++;
	return (get_res(&nptr[i], error) * sign);
}
