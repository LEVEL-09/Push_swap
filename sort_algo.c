/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:09:00 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/03 19:00:27 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list	**head)
{
	t_list	*last;

	last = ft_lstlast(*head);
	if ((*head)->next->content > last->content)
	{
		reverse_rotate(head);
		ft_printf("rra\n");
	}
	if ((*head)->content > (*head)->next->content)
	{
		swap(*head);
		ft_printf("sa\n");
	}
	else if ((*head)->next->content > last->content)
	{
		swap(*head);
		ft_printf("sa\n");
		rotate(head);
		ft_printf("ra\n");
	}
	
}