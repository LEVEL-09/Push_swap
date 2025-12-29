/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:43 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/29 18:00:20 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **stack)
{
	int	i;
	int	*p;
	int	old_ac;
	int	result;

	i = 1;
	old_ac = ac;
	p = malloc(sizeof(int) * (ac - 1));
	if (!p)
		exit(1);
	while (ac-- > 1)
	{
		// printf("{%d}", ac-1);
		if ((!validate_stack(*(stack+i))))
		{
			ft_printf("Error\n");
			return (1);
		}
		result = ft_atoi((const char*)*(stack+i++));
		p[ac - 1] = result;
	}
	if (check_double(p, old_ac))
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
