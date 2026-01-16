/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:43 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/16 02:43:02 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	temp = ft_atoi(*args, head_a, args);
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

int	push_swap(int ac, char **av)
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
	if (ft_lstsize(head_a) == 3 || ft_lstsize(head_a) == 2)
		sort_three_elements(&head_a);
	else if (ft_lstsize(head_a) == 5 || ft_lstsize(head_a) == 4)
		sort_five_elements(&head_a, &head_b);
	else
		fake_or_not(&head_a, &head_b);
	free_stack(head_a);
	return (0);
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}
