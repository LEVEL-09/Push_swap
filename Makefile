NAME_1 = push_swap

NAME_2 = checker

SRCS = push_swap.c push_swap_util.c push_swap_moves.c sort_algo.c push_swap_util2.c \
		chunk_algo.c fake_chunk_algo.c

SRCB = bonus/checker_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
		bonus/checker_util_bonus.c

OBJS = $(SRCS:.c=.o)

OBJB = $(SRCB:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_1)

bonus: $(NAME_2)

$(NAME_2): $(OBJB)
	make -C Printf/
	make bonus -C Libft/
	$(CC) $(OBJB) Libft/libft.a Printf/libftprintf.a -o $(NAME_2)

$(NAME_1): $(OBJS)
	make -C Printf/
	make bonus -C Libft/
	$(CC) $(OBJS) Libft/libft.a Printf/libftprintf.a -o $(NAME_1)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C Libft/
	make clean -C Printf/
	rm -f $(OBJS)
	rm -f $(OBJB)

fclean: clean
	make fclean -C Libft/
	make fclean -C Printf/
	rm -f $(NAME_1)
	rm -f $(NAME_2)

re: fclean all

.PHONY: all clean fclean re