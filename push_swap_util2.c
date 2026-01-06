/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_uti2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:18:45 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/06 12:26:33 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	find_position(t_list *head, int index)
{
	int i;
	
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
		return (0); // rr
	else
		return (1); // r
}