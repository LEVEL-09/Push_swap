/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:55:35 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/11/11 09:33:43 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hex(size_t n, int *cont, int f, char text)
{
	char	*hextab;

	if (f)
	{
		if (text == 'p' && !n)
		{
			*cont += write(1, "(nil)", 5);
			return ;
		}
		else if (text == 'p')
			*cont += write(1, "0x", 2);
		f = 0;
	}
	hextab = "0123456789abcdef";
	if (n / 16 != 0)
		hex(n / 16, cont, f, text);
	*cont += write(1, &hextab[n % 16], 1);
}
