/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:59:40 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/13 21:00:30 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_stack(char *av)
{
	int		i;

	i = 0;
	if (!av)
		return (ft_printf("Error\n"), free(av), exit(1));
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!av[i])
		return (ft_printf("Error\n"), free(av), exit(1));
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
			return (ft_printf("Error\n"), free(head), exit(1));
		head = head->next;
	}
}

t_list	*ft_lstlast_before(t_list *lst)
{
	int	i;

	i = ft_lstsize(lst) - 1;
	while (i-- > 1)
	{
		lst = lst->next;
	}
	return (lst);
}

void	set_index(t_list *node)
{
	int		j;
	t_list	*tmp;
	t_list	*node2;

	tmp = node;
	while (node)
	{
		j = 0;
		node2 = tmp;
		while (node2)
		{
			if (node->content > node2->content)
				j++;
			node2 = node2->next;
		}
		node->index = j;
		node = node->next;
	}
}
