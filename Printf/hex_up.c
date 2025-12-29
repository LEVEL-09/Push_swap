/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:02:26 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/11/08 09:16:04 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hex_up(unsigned int n, int *cont)
{
	char	*hextab;

	hextab = "0123456789abcdef";
	if (n / 16 != 0)
	{
		hex_up(n / 16, cont);
	}
	n = ft_toupper(hextab[n % 16]);
	*cont += write(1, &n, 1);
}
