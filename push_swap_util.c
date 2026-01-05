/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:59:40 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/05 14:29:28 by mkhoubaz         ###   ########.fr       */
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
	int		j;
	int		min_number;
	t_list	*temp;
	t_list	*store;
	t_list	**array;

	store = node;
	i = 0;
	j = ft_lstsize(node);
	array = (t_list **)calloc(sizeof(t_list *), j + 1);
	if (!array)
		return ;
	temp = node;
	while (j)
	{
		min_number = node->content;
		while (node)
		{
			if (!(node->next))
				break ;
			node = node->next;
			if (min_number > node->content && find(array, node))
			{
				// printf("{%d}\n", store->content);
				printf("{%d}\n", min_number);
				store = node;
				// printf("{%d}\n", store->content);
				min_number = node->content;
				printf("{%d}\n", min_number);
			}
		}
		if (store)
			store->index = i;
		printf("val:%d\n", store->content);
		printf("ind:%d\n", store->index);
		*(array + i++) = store;
		node = temp;
		j--;
	}
	// printf("{%d}\n", temp->index);
}
