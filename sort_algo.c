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

void	sort_3(t_list **head_a, t_list **head_b)
{
	t_list	*last;

	if (ft_lstsize(*head_a) == 2 && (*head_a)->content > (*head_a)->next->content)
	{
		swap(*head_a);
		printf("sa\n");
		return ;
	}
	last = ft_lstlast(*head_a);
	if ((*head_a)->content > (*head_a)->next->content)
	{
		swap(*head_a);
		printf("sa\n");
	}
	if ((*head_a)->next->content > last->content)
	{
		push(head_b, head_a);
		printf("pb\n");
		swap(*head_a);
		printf("sa\n");
		push(head_a, head_b);
		printf("pa\n");
	}
	if ((*head_a)->content > (*head_a)->next->content)
	{
		swap(*head_a);
		printf("sa\n");
	}
}
