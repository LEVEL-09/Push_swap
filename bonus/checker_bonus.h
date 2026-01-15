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

#endif