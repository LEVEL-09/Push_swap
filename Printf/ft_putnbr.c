/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:32:39 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/11/08 09:13:34 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(long n, int fd, int *cont)
{
	if (n < 0)
	{
		*cont += write(fd, "-", 1);
		n = n * -1;
	}
	if (n / 10 != 0)
	{
		ft_putnbr(n / 10, fd, cont);
		n = n % 10;
	}
	n = n + '0';
	*cont += write(fd, &n, 1);
}
