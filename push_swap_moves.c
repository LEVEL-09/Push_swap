/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:49:54 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/02 15:27:23 by mkhoubaz         ###   ########.fr       */
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

void	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*last;

	if (!head || !(*head))
		return ;
	temp = *head;
	last = ft_lstlast(*head);
	last->next = *head;
	*head = (*head)->next;
	temp->next = NULL;
}

void	reverse(t_list **head)
{
	t_list	*last;
	t_list	*temp;

	if (!head || !(*head))
		return ;
	temp = ft_lstlast_before(*head);
	last = ft_lstlast(*head);
	last->next = *head;
	*head = last;
	temp->next = NULL;
}
