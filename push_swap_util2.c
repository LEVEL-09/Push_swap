/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:18:45 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/10 16:33:43 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_list *head, int index)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->index == index)
			return (i);
		i++;
		head = head->next;
	}
	return (i);
}

int	top_or_down(int postion, int size)
{
	int	result;

	result = size / 2;
	if (postion >= result)
		return (0);
	else
		return (1);
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
