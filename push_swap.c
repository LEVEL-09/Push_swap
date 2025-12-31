/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:43 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/31 17:32:46 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **av)
{
	// All this can be in other file
	t_list *HEAD;
	char	**args;
	int		i;
	int		temp;

	i = 1;
	HEAD = 	NULL;
	if (ac == 1)
		return (1);
	while (i < ac)
	{
		args = ft_split(*(av + i++), ' ');
		while (*args)
		{
			validate_stack(*args); 
			temp = ft_atoi((const char *)*args);
			if (!HEAD)
			{
				HEAD->content = &temp;
			}
			args += 1;
		}
	}
	int *x = HEAD->content;
	printf("{%d}\n", *x);
	return (1);
}
