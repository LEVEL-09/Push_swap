/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:46 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/02 10:46:18 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> // for test

#include "Libft/libft.h"
#include "Printf/libftprintf.h"

void	swap(t_list *element);
void	validate_stack(char *av);
int		push_swap(int ac, char **stack);
void	push(t_list **dst, t_list **src);
void	check_double(t_list *head, int temp);

#endif