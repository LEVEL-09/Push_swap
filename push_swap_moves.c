/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:49:54 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/05 21:12:01 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *element)
{
	int	temp;
	int	ind_tmp;
	
	if (!element || !(element->next))
		return ;
	temp = element->content;
	element->content = element->next->content;
	element->next->content = temp;

	ind_tmp = element->index;
	element->index = element->next->index;
	element->next->index = ind_tmp;
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

void	reverse_rotate(t_list **head)
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
