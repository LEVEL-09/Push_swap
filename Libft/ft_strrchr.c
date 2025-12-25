/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 07:50:01 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/10/30 11:03:32 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	flag;
	int	point;

	i = 0;
	flag = 0;
	point = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
		{
			flag = 1;
			point = i;
		}
		i++;
	}
	if (s[i] == (const char)c)
	{
		flag = 1;
		point = i;
	}
	if (flag)
		return ((char *)s + point);
	else
		return (NULL);
}
