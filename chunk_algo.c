/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:39:51 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/10 17:13:53 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk_size(int size)
{
	if (size <= 100)
		return (13);
	else if (size <= 500)
		return (30);
	else
		return (69);
}

void	chunk_stack_b(t_list **head_a, t_list **head_b, int size)
{
	int	i;
	int	rr_r;
	int	big_index;

	big_index = find_position((*head_b), size - 1);
	while (*head_b)
	{
		rr_r = top_or_down(big_index, size);
		if (!rr_r)
		{
			i = size - big_index;
			while (i--)
				reverse_rotate(head_b, 'b');
		}
		else
		{
			i = big_index;
			while (i--)
				rotate(head_b, 'b');
		}
		push(head_a, head_b, 'a');
		chunk_stack_b(head_a, head_b, size - 1);
	}
}

void	chunk_sort(t_list **head_a, t_list **head_b)
{
	int		rr_r;
	int		small;
	int		flag;
	t_chunk	chunky;

	chunky.chunk_start = 0;
	flag = is_even_then_odd_desc(*head_a);
	chunky.chunk_end = calculate_chunk_size(ft_lstsize(*head_a));
	if (!flag)
	{
		while (*head_a)
		{
			if ((*head_a)->index <= chunky.chunk_start)
			{
				push(head_b, head_a, 'b');
				chunky.chunk_start++;
			}
			else if ((*head_a)->index <= chunky.chunk_start + chunky.chunk_end)
			{
				push(head_b, head_a, 'b');
				rotate(head_b, 'b');
				chunky.chunk_start++;
			}
			else
				rotate(head_a, 'a');
		}
	}
	else
	{
		while (*head_a)
		{
			small = find_position(*head_a, chunky.chunk_start);
			rr_r = top_or_down(small, ft_lstsize(*head_a));
			if ((*head_a)->index <= chunky.chunk_start)
			{
				push(head_b, head_a, 'b');
				chunky.chunk_start++;
			}
			else if ((*head_a)->index <= chunky.chunk_start + chunky.chunk_end)
			{
				push(head_b, head_a, 'b');
				rotate(head_b, 'b');
				chunky.chunk_start++;
			}
			else
			{
				if (rr_r)
					rotate(head_a, 'a');
				else
					reverse_rotate(head_a, 'a');
			}
		}
	}
	chunk_stack_b(head_a, head_b, ft_lstsize(*head_b));
}
