/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:09:00 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/06 12:33:50 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_list **head_a)
{
	if (ft_lstsize(*head_a) == 2 && (*head_a)->content > (*head_a)->next->content)
		return (swap(*head_a), ft_printf("sa\n"), 1);
	if ((*head_a)->next->content > (*head_a)->next->next->content)
	{
		reverse_rotate(head_a);
		ft_printf("rra\n");
	}
	if ((*head_a)->next->content > (*head_a)->next->next->content)
	{
		reverse_rotate(head_a);
		ft_printf("rra\n");
	}
	if ((*head_a)->content > (*head_a)->next->content)
	{
		swap(*head_a);
		ft_printf("sa\n");
	}
	if ((*head_a)->content > (*head_a)->next->next->content)
	{
		reverse_rotate(head_a);
		ft_printf("rra\n");
	}
	return (0);
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

int	sort_4(t_list **head_a, t_list **head_b)
{
	top_or_down(find_position(*head_a, 0), ft_lstsize(*head_a));
	return (1);
}
int	sort_5(t_list **head_a, t_list **head_b)
{
	if (ft_lstsize(*head_a) == 4 && is_sort(*head_a))
	{
		sort_4(head_a, head_b);
		return (1);
	}
	return (1);
}
