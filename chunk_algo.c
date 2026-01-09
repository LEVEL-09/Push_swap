/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:39:51 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/09 11:35:08 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_chunksize(int size)
{
	if (size <= 100)
		return (13);
	else if (size <= 500)
		return (37);
	else
		return (69);
}

void	chunk_stack_b(t_list **head_a, t_list **head_b, int size)
{
	int	i;
	int	rr_r;
	int big_index;

	big_index = find_position((*head_b), size - 1);
	while (*head_b)
	{
		rr_r = top_or_down(big_index, size);
		if (!rr_r)
		{
			i = size - big_index;
			while (i--)
			{
				reverse_rotate(head_b);
				ft_printf("rrb\n");
			}
		}
		else
		{
			i = big_index;
			while (i--)
			{
				rotate(head_b);
				ft_printf("rb\n");
			}
			
		}
		push(head_a, head_b);
		ft_printf("pa\n");
		chunk_stack_b(head_a, head_b, size - 1);
	}
}

void	chunk_sort(t_list **head_a, t_list **head_b)
{
	chunk chunky;

	chunky.chunk_start = 0;
	chunky.chunk_end = set_chunksize(ft_lstsize(*head_a));
	while (*head_a)
	{
		if ((*head_a)->index <= chunky.chunk_start)
		{
			push(head_b, head_a);
			ft_printf("pb\n");
			chunky.chunk_start++;
		}
		else if ((*head_a)->index <= chunky.chunk_start + chunky.chunk_end)
		{
			push(head_b, head_a);
			ft_printf("pb\n");
			rotate(head_b);
			ft_printf("rb\n");
			chunky.chunk_start++;
		}
		else
		{
			rotate(head_a);
			ft_printf("ra\n");
		}
	}
	chunk_stack_b(head_a, head_b, ft_lstsize(*head_b));
}
