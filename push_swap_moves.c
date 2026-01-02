/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:49:54 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/02 11:06:12 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *element)
{
	int	temp;
	
	if (!element || !(element->next))
		return ;
	temp = element->content;
	element->content = element->next->content;
	element->next->content = temp;
}

void	push(t_list **dst, t_list **src)
{
	t_list	*temp;

	if (!src || !(*src))
		return ;
	temp = (*src)->next;
	ft_lstadd_front(dst, *src);
	*src = temp;
}
