/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:35:01 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/16 03:00:15 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	validate_stack(char *av)
{
	int		i;

	i = 0;
	if (!av)
		return (1);
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!av[i])
		return (1);
	while (av[i])
	{
		if (!(ft_isdigit(av[i])))
			return (1);
		i++;
	}
	return (0);
}

int	check_double(t_list *head, int temp)
{
	while (head)
	{
		if (head->content == temp)
			return (1);
		head = head->next;
	}
	return (0);
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

int	is_sort(t_list *head_a)
{
	int	i;

	i = 0;
	while (head_a)
	{
		if (i++ != head_a->index)
			return (1);
		head_a = head_a->next;
	}
	return (0);
}
