/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util3.5_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:50:14 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/15 21:55:28 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ra(char	*s)
{
	if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		return (1);
	return (0);
}

int	rb(char	*s)
{
	if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		return (1);
	return (0);
}

int	rr(char	*s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		return (1);
	return (0);
}

int	rra(char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		return (1);
	return (0);
}

int	rrb(char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		return (1);
	return (0);
}
