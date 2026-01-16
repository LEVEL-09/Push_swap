/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:42:10 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/15 21:51:06 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	sa(char	*s)
{
	if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		return (1);
	return (0);
}

int	sb(char	*s)
{
	if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		return (1);
	return (0);
}

int	ss(char	*s)
{
	if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		return (1);
	return (0);
}

int	pa(char	*s)
{
	if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		return (1);
	return (0);
}

int	pb(char	*s)
{
	if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		return (1);
	return (0);
}
