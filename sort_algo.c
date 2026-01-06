/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:09:00 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/06 16:35:22 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_list **head_a)
{
	if (ft_lstsize(*head_a) == 2 && (*head_a)->content > (*head_a)->next->content)
		return (swap(*head_a), ft_printf("sa\n"), 1);
	if ((*head_a)->content > (*head_a)->next->content)
	{
		swap(*head_a);
		ft_printf("sa\n");
	}
	if ((*head_a)->content > (*head_a)->next->content
		&& (*head_a)->next->content < (*head_a)->next->next->content)
	{
		rotate(head_a);
		ft_printf("ra\n");
	}
	if ((*head_a)->content > (*head_a)->next->next->content)
	{
		reverse_rotate(head_a);
		ft_printf("rra\n");
	}
	if ((*head_a)->next->content > (*head_a)->next->next->content)
	{
		reverse_rotate(head_a);
		ft_printf("rra\n");
		swap(*head_a);
		ft_printf("sa\n");
	}
	return (0);
}

int	sort_4(t_list **head_a, t_list **head_b, int flag)
{
	int	i;

	i = find_position(*head_a, 0);
	if (i == 1)
	{
		rotate(head_a);
		ft_printf("ra\n");
	}
	else if (i == 2)
	{
		rotate(head_a);
		ft_printf("ra\n");
		rotate(head_a);
		ft_printf("ra\n");
	}
	else if (i == 3 || i == 4)
	{
		reverse_rotate(head_a);
		ft_printf("rra\n");
	}
	if (flag)
	{
		if (i == 3)
		{
			reverse_rotate(head_a);
			ft_printf("rra\n");
		}
		push(head_b, head_a);
		ft_printf("pb\n");
		return (1);
	}
	push(head_b, head_a);
	ft_printf("pb\n");
	sort_3(head_a);
	push(head_a, head_b);
	ft_printf("pa\n");
	return (1);
}

int	sort_5(t_list **head_a, t_list **head_b)
{
	if (ft_lstsize(*head_a) == 4)
	{
		sort_4(head_a, head_b, 0);
		return (1);
	}
	sort_4(head_a, head_b, 1);
	sort_4(head_a, head_b, 0);
	push(head_a, head_b);
	ft_printf("pa\n");
	return (1);
}
