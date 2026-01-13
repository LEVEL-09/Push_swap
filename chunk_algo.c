/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:39:51 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/13 21:04:12 by mkhoubaz         ###   ########.fr       */
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

void	chunk_stack_b(t_list **head_a, t_list **head_b, int size, int *count)
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
				reverse_rotate(head_b, 'b');
				(*count)++;
			}
		}
		else
		{
			i = big_index;
			while (i--)
			{
				rotate(head_b, 'b');
				(*count)++;
			}
		}
		push(head_a, head_b, 'a');
		(*count)++;
		chunk_stack_b(head_a, head_b, --size, count);
	}
}

int	chunk_sort(t_list **head_a, t_list **head_b)
{
	t_chunk	chunky;
	int		count;

	count = 0;
	chunky.chunk_start = 0;
	chunky.chunk_end = calculate_chunk_size(ft_lstsize(*head_a));
	while (*head_a)
	{
		if ((*head_a)->index <= chunky.chunk_start)
		{
			push(head_b, head_a, 'b');
			count++;
			chunky.chunk_start++;
		}
		else if ((*head_a)->index <= chunky.chunk_start + chunky.chunk_end)
		{
			push(head_b, head_a, 'b');
			count++;
			rotate(head_b, 'b');
			count++;
			chunky.chunk_start++;
		}
		else
		{
			rotate(head_a, 'a');
			count++;
		}
	}
	chunk_stack_b(head_a, head_b, ft_lstsize(*head_b), &count);
	return (count);
}

void	fake_or_not(t_list **head_a, t_list **head_b)
{
	int count;

	
	count = fake_chunk_sort(head_a, head_b);

	printf("fake count:%d\n", count);
	// if (count >= 700 && ft_lstsize(*head_a) == 100)
	// 	reverse_chunk_sort(head_a, head_b);
	// else if (count >= 5500 && ft_lstsize(*head_a) == 500)
	// 	reverse_chunk_sort(head_a, head_b);
	// else
	
	count = chunk_sort(head_a, head_b);
	printf("count:%d\n", count);
}
