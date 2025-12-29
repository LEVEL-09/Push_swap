/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:59:40 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/29 18:07:02 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_stack(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (!(ft_isdigit(av[i])))
			return (0);
		i++;
	}
	return (1);
}
int	check_double(int *p, int size)
{
	int	*i;
	int	idx;

	i = malloc(sizeof(int) * size);
	if (!i)
		return (-1);
	ft_bzero(i, (size_t)size);
	while (size-- > 0)
	{
		idx = p[size];
		printf("%d\n", p[size]);
		if (i[idx])
			return (1);
		i[idx] = 1;
	}
	return (0);
}
