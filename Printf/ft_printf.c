/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:51:42 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/11/11 11:36:16 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	arg(const char *text, int i, va_list list, int *cont)
{
	va_list	cpy;

	if (text[i] == 'c')
		return (ft_putchar(va_arg(list, int), 1));
	else if (text[i] == '%')
		return (write(1, "%", 1));
	else if (text[i] == 'd' || text[i] == 'i')
		ft_putnbr(va_arg(list, int), 1, cont);
	else if (text[i] == 'u')
		ft_putnbr((unsigned int)va_arg(list, int), 1, cont);
	else if (text[i] == 'x')
		hex(va_arg(list, unsigned int), cont, 1, text[i]);
	else if (text[i] == 'X')
		hex_up(va_arg(list, unsigned int), cont);
	else if (text[i] == 'p')
		hex(va_arg(list, size_t), cont, 1, text[i]);
	va_copy(cpy, list);
	if (text[i] == 's' && !va_arg(cpy, char *))
	{
		va_arg(list, char *);
		return (va_end(cpy), write(1, "(null)", 6));
	}
	else if (text[i] == 's')
		return (va_end(cpy), ft_putstr(va_arg(list, char *), 1));
	return (va_end(cpy), 0);
}

int	ft_printf(const char *text, ...)
{
	va_list	list;
	int		i;	
	int		cont;

	va_start(list, text);
	i = 0;
	cont = 0;
	if (!text || 0 > write(1, 0, 0))
		return (-1);
	while (text[i])
	{
		if (text[i] == '%')
		{
			i++;
			cont += arg(text, i, list, &cont);
			if (!text[i++])
				break ;
		}
		else
		{
			write(1, &text[i++], 1);
			cont++;
		}
	}
	return (va_end(list), cont);
}
