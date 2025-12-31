/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:43 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/31 13:58:04 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int ac, char **av)
{
	// All this can be in other file
	t_list *HEAD;
	char	**args;
	int		i;
	int		temp;

	i = 1;
	HEAD = ft_lstnew(0);
	while (i < ac)
	{
		args = ft_split(*(av + i++), ' ');
		while (*args)
		{
			validate_stack(*args); 
			temp = ft_atoi((const char *)*args);
			if (!(HEAD->content))
				HEAD->content = temp;
			args += 1;
		}
	}
	printf("%d\n", HEAD->content);
	return (1);
}
