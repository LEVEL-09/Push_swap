/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:59:40 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/01 04:46:39 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_stack(char *av)
{
	int		i;

	i = 0;
	if (!av)
		return (ft_printf("Error\n"), exit(1));
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (!(ft_isdigit(av[i])))
			return (ft_printf("Error\n"), exit(1));
		i++;
	}
}

void	check_double(t_list *head, int temp)
{
	while (head)
	{
		if (head->content == temp)
			return (ft_printf("DError\n"), exit(1));
		head = head->next;
	}
}
