/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:09:00 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/14 10:20:41 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smaller(t_list **head_a, t_list **head_b, int index)
{
	int	i;
	int	j;
	int	size;
	int	rr_r;

	i = find_position(*head_a, index);
	size = ft_lstsize(*head_a);
	rr_r = top_or_down(i, size);
	if (rr_r)
	{
		while (i--)
			rotate(head_a, 'a');
	}
	else
	{
		j = size - i;
		while (j--)
			reverse_rotate(head_a, 'a');
	}
	push(head_b, head_a, 'b');
}

void	sort_three_elements(t_list **head_a)
{
	if (ft_lstsize(*head_a) == 2
		&& (*head_a)->content > (*head_a)->next->content)
	{
		swap(*head_a, 'a');
		return ;
	}
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
}

void	sort_four_elements(t_list **head_a, t_list **head_b, int i)
{
	find_smaller(head_a, head_b, i);
	sort_three_elements(head_a);
	push(head_a, head_b, 'a');
}

void	sort_five_elements(t_list **head_a, t_list **head_b)
{
	if (ft_lstsize(*head_a) == 4)
	{
		sort_four_elements(head_a, head_b, 0);
		return ;
	}
	find_smaller(head_a, head_b, 0);
	sort_four_elements(head_a, head_b, 1);
	push(head_a, head_b, 'a');
}
