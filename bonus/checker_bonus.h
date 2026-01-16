/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 03:00:46 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/16 03:01:10 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line_bonus.h"
# include "../Printf/libftprintf.h"
# include "../Libft/libft.h"

void	free_args(char **args);
void	set_index(t_list *node);
int		is_sort(t_list *head_a);
int		validate_stack(char *av);
void	free_stack(t_list *head_a);
t_list	*ft_lstlast_before(t_list *lst);
int		check_double(t_list *head, int temp);
void	not_move(t_list **head_a, t_list **head_b);

int		sa(char *s);
int		sb(char *s);
int		ss(char *s);
int		pa(char *s);
int		pb(char *s);
int		ra(char *s);
int		rb(char *s);
int		rr(char *s);
int		rra(char *s);
int		rrb(char *s);
int		rrr(char *s);

int		swap(t_list *element, char c);
int		rotate(t_list **head, char c);
int		reverse_rotate(t_list **head, char c);
int		push(t_list **dst, t_list **src, char c);

#endif