/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 08:49:54 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/14 09:35:04 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *element, char c)
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
	if (c != 'x')
		ft_printf("s%c\n", c);
}

void	push(t_list **dst, t_list **src, char c)
{
	t_list	*temp;

	if (!src || !(*src))
		return ;
	temp = (*src)->next;
	ft_lstadd_front(dst, *src);
	*src = temp;
	if (c != 'x')
		ft_printf("p%c\n", c);
}

void	rotate(t_list **head, char c)
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
	if (c != 'x')
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_list **head, char c)
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
	if (c != 'x')
		ft_printf("rr%c\n", c);
}
