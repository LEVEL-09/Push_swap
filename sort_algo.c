/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:09:00 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/05 22:08:25 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_list **head_a, t_list **head_b)
{
	t_list	*last;

	if (ft_lstsize(*head_a) == 2 && (*head_a)->content > (*head_a)->next->content)
	{
		swap(*head_a);
		ft_printf("sa\n");
		return (1);
	}
	last = ft_lstlast(*head_a);
	if ((*head_a)->content > (*head_a)->next->content)
	{
		swap(*head_a);
		ft_printf("sa\n");
	}
	if ((*head_a)->next->content > last->content)
	{
		push(head_b, head_a);
		ft_printf("pb\n");
		swap(*head_a);
		ft_printf("sa\n");
		push(head_a, head_b);
		ft_printf("pa\n");
	}
	if ((*head_a)->content > (*head_a)->next->content)
		return (swap(*head_a), ft_printf("sa\n"), 1);
	return (0);
}

int	sort_5(t_list **head_a, t_list **head_b)
{
	int	i;
	int	j;
	if ((*head_a)->content > (*head_a)->next->content)
	{
		swap(*head_a);
		ft_printf("sa\n");
	}
	push(head_b, head_a);
	ft_printf("pb\n");
	push(head_b, head_a);
	ft_printf("pb\n");
	sort_3(head_a, head_b);
	i = (*head_b)->index - 1;
	j = i;
	while (i--)
	{
		rotate(head_a);
		ft_printf("ra\n");
	}
	push(head_a, head_b);
	ft_printf("pa\n");
	if ((*head_a)->index == (*head_b)->index + 1)
	{
		push(head_a, head_b);
		ft_printf("pa\n");
		i =	j + 1;
		while (i--)
		{
			rotate(head_a);
			ft_printf("ra\n");
		}
		return (1);
	}
	i =	j;
	while (i--)
	{
		rotate(head_a);
		ft_printf("ra\n");
	}
	push(head_a, head_b);
	ft_printf("pa\n");
	i = (*head_a)->index - 1;
	if (i == -1)
		return (1);
	while (i--)
	{
		rotate(head_a);
		ft_printf("ra\n");
	}
	return (1);
}
