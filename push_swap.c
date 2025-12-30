/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:43 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/30 12:07:50 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **stack)
{
	int	i;
	int	*p;
	int	old_ac;

	i = 1;
	old_ac = ac - 1;
	p = malloc(sizeof(int) * (ac - 1));
	if (!p)
		exit(1);
	while (ac-- > 1)
	{
		if ((!validate_stack(*(stack+i))))
			return (free(p), ft_printf("Error\n"), 1);
		p[i - 1] = ft_atoi((const char*)*(stack+i));
		i++;
	}
	if (check_double(p, old_ac))
		return (free(p), ft_printf("Error\n"), 1);
	return (0);
}
