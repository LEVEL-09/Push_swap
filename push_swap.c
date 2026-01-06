/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:43 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/06 10:57:50 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **av)
{
	char	**args;
	t_list	*head_a;
	t_list	*head_b;
	t_list	*new;
	int		temp;
	int		i;

	i = 1;
	head_a = NULL;
	head_b = NULL;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		args = ft_split(*(av + i++), ' ');
		validate_stack(*args); 
		while (*args)
		{
			temp = ft_atoi((const char *)*args);
			if (!head_a)
				head_a = ft_lstnew(temp);
			else
			{
				check_double(head_a, temp);
				new = ft_lstnew(temp);
				ft_lstadd_back(&head_a, new);
			}
			args += 1;
		}
	}
	set_index(head_a);
	if (ft_lstsize(head_a) == 3 || ft_lstsize(head_a) == 2)
		sort_3(&head_a);
	else if (ft_lstsize(head_a) == 5 || ft_lstsize(head_a) == 4)
		sort_5(&head_a, &head_b);
	while (head_a)
	{
		ft_printf("%d %d\n", head_a->content, head_a->index);
		head_a = head_a->next;
	}
	return (0);
}
