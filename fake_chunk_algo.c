/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_chunk_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:35:28 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/13 21:08:35 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fake_chunk_stack_b(t_list **head_a, t_list **head_b, int size, int *count)
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
			{
				reverse_rotate(head_b, 'x');
				(*count)++;
			}
		}
		else
		{
			i = big_index;
			while (i--)
			{
				rotate(head_b, 'x');
				(*count)++;
			}
		}
		push(head_a, head_b, 'x');
		(*count)++;
		fake_chunk_stack_b(head_a, head_b, --size, count);
	}
}

int	fake_chunk_sort(t_list **copy_a, t_list **head_b)
{
	t_chunk	chunky;
	int		count;
	t_list *head_a;
	head_a = ft_lstmap(*copy_a);
	
	count = 0;
	chunky.chunk_start = 0;
	chunky.chunk_end = calculate_chunk_size(ft_lstsize(head_a));
	while (head_a)
	{
		if (head_a->index <= chunky.chunk_start)
		{
			push(head_b, &head_a, 'x');
			count++;
			chunky.chunk_start++;
		}
		else if (head_a->index <= chunky.chunk_start + chunky.chunk_end)
		{
			push(head_b, &head_a, 'x');
			count++;
			rotate(head_b, 'x');
			count++;
			chunky.chunk_start++;
		}
		else
		{
			rotate(&head_a, 'x');
			count++;
		}
	}
	fake_chunk_stack_b(&head_a, head_b, ft_lstsize(*head_b), &count);
	return (count);
}
