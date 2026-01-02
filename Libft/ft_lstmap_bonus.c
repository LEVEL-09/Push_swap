/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:29:45 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/02 08:32:59 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new;
	t_list	*node_lst;
	int		new_content;

	if (!f || !del)
		return (NULL);
	node_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			del(new_content);
			ft_lstclear(&node_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&node_lst, new);
		lst = lst->next;
	}
	return (node_lst);
}
