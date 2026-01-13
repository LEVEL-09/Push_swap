#include "push_swap.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:43 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/10 12:12:49 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a)
		{
			printf("%4d", a->content);
			a = a->next;
		}
		else
			printf("    ");

		printf("    "); 

		if (b)
		{
			printf("%4d", b->content);
			b = b->next;
		}
		else
			printf("    ");

		printf("\n");
	}
	printf("----    ----\n");
	printf("  a        b\n");
}

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
	new = NULL;
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		args = ft_split(*(av + i++), ' ');
		if (!(*args))
			return (ft_printf("Error\n"), free(*args), free(args), free(new), exit(1), 1);
		while (*args)
		{
			validate_stack(*args); 
			temp = ft_atoi((const char *)*args);
			if (!head_a)
				head_a = ft_lstnew(temp);
			else
			{
				check_double(head_a, temp);
				new = ft_lstnew(temp);
				ft_lstadd_back(&head_a, new);
			}
			args++;
		}
		free(*args);
	}
	set_index(head_a);
	if (!is_sort(head_a))
		return (1);
	if (ft_lstsize(head_a) == 3 || ft_lstsize(head_a) == 2)
		sort_three_elements(&head_a);
	else if (ft_lstsize(head_a) == 5 || ft_lstsize(head_a) == 4)
		sort_five_elements(&head_a, &head_b);
	else
		fake_or_not(&head_a, &head_b);
	// print_stacks(head_a, head_b);
	return (0);
}

int main(int ac, char **av)
{
	push_swap(ac, av);
}