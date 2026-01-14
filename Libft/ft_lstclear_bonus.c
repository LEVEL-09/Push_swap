/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:48:48 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/02 08:30:05 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*p;

	if (!lst)
		return ;
	while (*lst)
	{
		p = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(p);
	}
	*lst = NULL;
}
