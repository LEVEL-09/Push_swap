/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:46 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/01 04:44:19 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> // for test

#include "Libft/libft.h"
#include "Printf/libftprintf.h"

int		push_swap(int ac, char **stack);
void	validate_stack(char *av);
void	check_double(t_list *head, int temp);

#endif