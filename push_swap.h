/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:32:46 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/29 17:36:31 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h> // for test

#include "Libft/libft.h"
#include "Printf/libftprintf.h"

int push_swap(int ac, char **stack);
int	validate_stack(char *av);
int	check_double(int *p, int size);

#endif