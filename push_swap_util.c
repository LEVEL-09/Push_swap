/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:59:40 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/31 23:35:33 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_stack(char *av)
{
	int		i;

	i = 0;
	if (!av)
		return (ft_printf("Error\n"), exit(1), 555);
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (!(ft_isdigit(av[i])))
			return (ft_printf("Error\n"), exit(1), 555);
		i++;
	}
	return (1);
}

int	check_double(int *p, int size)
{
	int	i;
	int	j;

	i = 0;	
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (p[i] == p[j])
			{
				free(p);
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
