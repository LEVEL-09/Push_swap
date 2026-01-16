/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:32:17 by mkhoubaz          #+#    #+#             */
/*   Updated: 2026/01/15 18:38:48 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t			ft_get_strlen(char *s);
char			*ft_get_substr(char *str);
char			*ft_subjoin(char *str);
char			*get_next_line(int fd);
char			*subs(char **line, char **buf);
char			*ft_get_strjoin(char *s1, char *s2);
char			*ft_strncpy(char *dest, char *src, unsigned int n);

#endif