/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 06:56:06 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/11/01 16:14:35 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_putnbr(char *ptr, int n, int *i)
{
	if (n / 10 != 0)
	{
		my_putnbr(ptr, n / 10, i);
	}
	*i += 1;
	ptr[*(i)] = (n % 10) + '0';
}

static char	*ptr_alloc(int i, int neg, int n)
{
	int		j;
	char	*ptr;

	ptr = malloc(sizeof(char) * (i + neg + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	if (neg == 1)
		ptr[j] = '-';
	else
		j = -1;
	my_putnbr(ptr, n, &j);
	ptr[j + 1] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		clone;
	int		i;
	int		neg;
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	i = 0;
	clone = n;
	while (clone != 0)
	{
		clone /= 10;
		i++;
	}
	ptr = ptr_alloc(i, neg, n);
	return (ptr);
}
