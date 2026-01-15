/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 02:29:57 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/15 22:40:39 by mkhoubaz         ###   ########.fr       */
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

int	is_move(char	*s, t_list **head_a, t_list **head_b)
{
	if (sa(s))
	{
		swap(*head_a, 'x');
		return (1);
	}
	else if (sb(s))
	{
		swap(*head_b, 'x');
		return (1);
	}
	else if (ss(s))
	{
		swap(*head_a, 'x');
		swap(*head_b, 'x');
		return (1);
	}
	else if (pa(s))
	{
		push(head_a, head_b, 'x');
		return (1);
	}
	else if (pb(s))
	{
		push(head_b, head_a, 'x');
		return (1);
	}
	else if (ra(s))
	{
		rotate(head_a, 'x');
		return (1);
	}
	else if (rb(s))
	{
		rotate(head_b, 'x');
		return (1);
	}
	else if (rr(s))
	{
		rotate(head_a, 'x');
		rotate(head_b, 'x');
		return (1);
	}
	else if (rra(s))
	{
		reverse_rotate(head_a, 'x');
		return (1);
	}
	else if (rrb(s))
	{
		reverse_rotate(head_b, 'x');
		return (1);
	}
	else if (rrr(s))
	{
		reverse_rotate(head_a, 'x');
		reverse_rotate(head_b, 'x');
		return (1);
	}
	return (0);
}

int	checker(int ac, char **av)
{
	t_list	*head_a;
	t_list	*head_b;
	char	*line;

	head_a = NULL;
	head_b = NULL;
	if (ac == 1)
		return (0);
	head_a = check(head_a, ac, av, 1);
	set_index(head_a);
	line = get_next_line(1);
	while (line)
	{
		if (!(is_move(line, &head_a, &head_b)))
		{
			free_stack(head_a);
			free_stack(head_b);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(line);
		line = get_next_line(1);
	}
	if (!is_sort(head_a))
	{
		write(1, "OK\n", 3);
		free_stack(head_a);
		return (0);
	}
	else
		write(1, "KO\n", 3);
	free_stack(head_a);
	return (0);
}

int main(int ac, char **av)
{
	checker(ac, av);
	return (0);
}
