/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:39:36 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/11/11 09:38:37 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *text, ...);
void	ft_putnbr(long n, int fd, int *cont);
int		ft_putstr(char *s, int fd);
int		ft_putchar(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
void	hex(size_t n, int *cont, int f, char text);
void	hex_up(unsigned int n, int *cont);

#endif