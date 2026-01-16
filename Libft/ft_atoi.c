/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:29:45 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/16 02:43:34 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

static int	check_sp(char s)
{
	if (s == ' ')
		return (1);
	return (0);
}

static int	ft_overflow(int neg, int cont, t_list **head_a, char **s)
{
	if (cont == -2147483648 && neg == -1)
		return (-2147483648);
	free_stack(*head_a);
	free(*s);
	free(s);
	write(2, "Error\n", 6);
	exit(1);
	return (1);
}

int	ft_atoi(char *str, t_list	**head_a, char **args)
{
	int		i;
	int		neg;
	int		cont;
	int		overflow;

	i = 0;
	neg = 1;
	while (check_sp(str[i]))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i++] == 45)
			neg = -1;
	}
	cont = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		overflow = cont;
		cont *= 10;
		cont = cont + (str[i] - '0');
		if (overflow != cont / 10)
			return (ft_overflow(neg, cont, head_a, args));
		i++;
	}
	return (cont * neg);
}
