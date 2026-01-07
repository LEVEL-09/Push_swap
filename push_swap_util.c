/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:59:40 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/07 10:35:21 by mkhoubaz         ###   ########.fr       */
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
	if(!av[i])
		return (ft_printf("Error\n"), exit(1));
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
			return (ft_printf("Error\n"), exit(1));
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

int	find(t_list **array, t_list *node)
{
	if (!(*array))
		return (1);
	while (*array)
	{
		if (*array == node)
			return (0);
		array++;
	}
	return (1);
}

void	set_index(t_list *node)
{
	int		i;
	int		tmp;
	int		size;
	t_list *temp;
	t_list *node_cp;

	i = 0;
	size = ft_lstsize(node) - 1;
	node_cp = ft_lstmap(node);
	temp = node_cp;
	while (size)
	{
		i = size;
		while (i)
		{
			if (temp->next == NULL)
				break ;
			if (temp->content > temp->next->content)
			{
				tmp = temp->content;
				temp->content = temp->next->content;
				temp->next->content = tmp;
			}
			temp = temp->next;
			i--;
		}
		temp = node_cp;
		size--;
	}
	temp = node_cp;
	while (temp)
	{
		temp->index = size;
		temp = temp->next;
		size++;
	}
	temp = node_cp;
	while (node)
	{
		node_cp = temp;
		while(node_cp)
		{
			if (node_cp->content == node->content)
				node->index = node_cp->index;
			node_cp = node_cp->next;
		}
		node = node->next;
	}
}
