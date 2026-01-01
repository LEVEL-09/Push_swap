/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:43 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/01 02:22:53 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **av)
{
	// All this can be in other file
	char	**args;
	t_list	*head;
	t_list	*new;
	int		temp;
	int		i;

	i = 1;
	head = NULL;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		args = ft_split(*(av + i++), ' ');
		validate_stack(*args); 
		while (*args)
		{
			temp = ft_atoi((const char *)*args);
			if (!head)
				head = ft_lstnew(temp);
			else
			{
				new = ft_lstnew(temp);
				ft_lstadd_back(&head, new);
			}
			args += 1;
		}
	}
	return (0);
}
