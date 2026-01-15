NAME_1 = push_swap

NAME_2 = push_swap.a

NAME_3 = checker

NAME_4 = checker.a

SRCS = push_swap.c push_swap_util.c push_swap_moves.c sort_algo.c push_swap_util2.c \
		chunk_algo.c fake_chunk_algo.c

SRCB = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

OBJB = $(SRCB:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_1)

bonus: $(NAME_3)

$(NAME_3): $(OBJB)
	make -C Printf/
	ar rc $(NAME_4) $(OBJB)
	$(CC) $(NAME_4) Printf/libftprintf.a -o $(NAME_3)

$(NAME_1): $(OBJS)
	make bonus -C Libft/
	make -C Printf/
	ar rc $(NAME_2) $(OBJS)
	$(CC) $(NAME_2) Libft/libft.a Printf/libftprintf.a -o $(NAME_1)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C Libft/
	make clean -C Printf/
	rm -f $(OBJS)
	rm -f $(OBJB)

fclean: clean
	make fclean -C Libft/
	make fclean -C Printf/
	rm -f $(NAME_2)
	rm -f $(NAME_1)
	rm -f $(NAME_4)
	rm -f $(NAME_3)

re: fclean all

.PHONY: all clean fclean re