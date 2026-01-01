/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:43 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/31 23:30:19 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **av)
{
	// All this can be in other file
	char	**args;
	int		i;
	int		temp;

	i = 1;
	if (ac == 1)
		return (0); // 0 or 1
	while (i < ac)
	{
		args = ft_split(*(av + i++), ' ');
		validate_stack(*args); 
		while (*args)
		{
			temp = ft_atoi((const char *)*args);
			args += 1;
		}
	}
	return (0);
}
