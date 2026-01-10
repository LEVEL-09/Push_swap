/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:46 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/10 11:49:53 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Printf/libftprintf.h"

typedef struct t_chunk{
	int	chunk_start;
	int	chunk_end;
}	t_chunk;

int		is_sort(t_list *head_a);
void	set_index(t_list *node);
void	validate_stack(char *av);
void	swap(t_list *element, char c);
void	rotate(t_list **head, char c);
t_list	*ft_lstlast_before(t_list *lst);
int		push_swap(int ac, char **stack);
int		top_or_down(int postion, int size);
void	check_double(t_list *head, int temp);
int		sort_three_elements(t_list **head_a);
void	reverse_rotate(t_list **head, char c);
int		find_position(t_list *head, int index);
void	push(t_list **dst, t_list **src, char c);
void	chunk_sort(t_list **head_a, t_list **head_b);
int		sort_five_elements(t_list **head_a, t_list **head_b);

#endif