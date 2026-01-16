/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:02:07 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/16 03:07:51 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_stack(t_list *head_a)
{
	t_list	*tmp;

	while (head_a)
	{
		tmp = head_a->next;
		free(head_a);
		head_a = tmp;
	}
}

void	free_args(char **args)
{
	char	**temp;

	while (*args)
	{
		temp = args + 1;
		free(*args);
		args = temp;
	}
}

int	rrr(char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		return (1);
	return (0);
}

void	not_move(t_list **head_a, t_list **head_b, char *line)
{
	free(line);
	free_stack(*head_a);
	free_stack(*head_b);
	write(2, "Error\n", 6);
	exit(1);
}
