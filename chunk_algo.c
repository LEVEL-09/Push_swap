/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:39:51 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/07 16:40:04 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_chunksize(int size)
{
	if (size <= 100)
		return (13);
	else if (size <= 500)
		return (50);
	else
		return (69);
}

void	chunk_stack_b(t_list **head_a, t_list **head_b, int size, int i)
{
	int	rr_r;
	int	index;
	int	size_index;

	index = find_position(*head_b, i);
	if (*head_b)
	{
		rr_r = top_or_down(index, size);
		if (!rr_r)
		{
			size_index = size - index;
			while (size_index--)
			{
				reverse_rotate(head_b);
				printf("rrb\n");
			}
			push(head_a, head_b);
			printf("pa\n");
		}
		else
		{
			while (index--)
			{
				rotate(head_b);
				printf("rb\n");
			}
			push(head_a, head_b);
			printf("pa\n");
		}
		chunk_stack_b(head_a, head_b, size--, i++);
	}
}

void	chunk_sort(t_list **head_a, t_list **head_b)
{
	int		size;
	chunk	chunky;

	chunky.chunk_start = 0;
	size = ft_lstsize(*head_a);
	chunky.chunk_end = set_chunksize(size);
	while (*head_a)
	{
		if ((*head_a)->content >= chunky.chunk_start 
			&& (*head_a)->content <= chunky.chunk_end)
		{
			push(head_b, head_a);
			printf("pb\n");
			chunky.chunk_start++;
		}
		else if ((*head_a)->content < chunky.chunk_start)
		{
			push(head_b, head_a);
			printf("pb\n");
			rotate(head_b);
			printf("rb\n");
		}
		else
		{
			rotate(head_a);
			printf("ra\n");
		}
	}
	chunk_stack_b(head_a, head_b, size, 0);
}
