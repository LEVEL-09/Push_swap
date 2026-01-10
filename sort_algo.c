/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:09:00 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/10 17:17:46 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three_elements(t_list **head_a)
{
	if (ft_lstsize(*head_a) == 2
		&& (*head_a)->content > (*head_a)->next->content)
		return (swap(*head_a, 'a'), 1);
	if ((*head_a)->content > (*head_a)->next->content)
		swap(*head_a, 'a');
	if ((*head_a)->content > (*head_a)->next->content
		&& (*head_a)->next->content < (*head_a)->next->next->content)
		rotate(head_a, 'a');
	if ((*head_a)->content > (*head_a)->next->next->content)
		reverse_rotate(head_a, 'a');
	if ((*head_a)->next->content > (*head_a)->next->next->content)
	{
		reverse_rotate(head_a, 'a');
		swap(*head_a, 'a');
	}
	return (0);
}

int	sort_four_elements(t_list **head_a, t_list **head_b, int flag)
{
	int	i;

	i = find_position(*head_a, 0);
	if (!flag)
		i = find_position(*head_a, 1);
	if (i == 1)
		rotate(head_a, 'a');
	else if (i == 2)
	{
		rotate(head_a, 'a');
		rotate(head_a, 'a');
	}
	else if (i == 3 || i == 4)
		reverse_rotate(head_a, 'a');
	if (flag)
	{
		if (i == 3)
			reverse_rotate(head_a, 'a');
		push(head_b, head_a, 'b');
		return (1);
	}
	push(head_b, head_a, 'b');
	sort_three_elements(head_a);
	push(head_a, head_b, 'a');
	return (1);
}

int	sort_five_elements(t_list **head_a, t_list **head_b)
{
	if (ft_lstsize(*head_a) == 4)
	{
		sort_four_elements(head_a, head_b, 0);
		return (1);
	}
	sort_four_elements(head_a, head_b, 1);
	sort_four_elements(head_a, head_b, 0);
	push(head_a, head_b, 'a');
	return (1);
}
