/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 02:29:57 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/15 18:05:12 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	fun(t_list	**head_a, char **args, char **ptr)
{
	int	temp;

	if (validate_stack(*args))
	{
		write(2, "Error\n", 6);
		free_args(args);
		free(ptr);
		free_stack(*head_a);
		exit(1);
	}
	temp = ft_atoi((const char *)*args);
	if (!(*head_a))
		*head_a = ft_lstnew(temp);
	else
	{
		if (check_double(*head_a, temp))
		{
			write(2, "Error\n", 6);
			free_args(args);
			free(ptr);
			free_stack(*head_a);
			exit(1);
		}
		ft_lstadd_back(head_a, ft_lstnew(temp));
	}
}

t_list	*check(t_list *head_a, int ac, char **av, int i)
{
	char	**args;
	char	**ptr;

	while (i < ac)
	{
		args = ft_split(*(av + i++), ' ');
		if (!args || !(*args))
		{
			write(2, "Error\n", 6);
			free(args);
			free_stack(head_a);
			exit(1);
		}
		ptr = args;
		while (*args)
		{
			fun(&head_a, args, ptr);
			free(*args);
			args++;
		}
		free(ptr);
	}
	return (head_a);
}

int	checker(int ac, char **av)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (ac == 1)
		return (0);
	head_a = check(head_a, ac, av, 1);
	set_index(head_a);
	if (!is_sort(head_a))
	{
		free_stack(head_a);
		return (0);
	}
	free_stack(head_a);
	return (0);
}

int main(int ac, char **av)
{
	checker(ac, av);
	return (0);
}
