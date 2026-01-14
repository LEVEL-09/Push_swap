NAME_1 = push_swap

NAME_2 = push_swap.a

SRCS = push_swap.c push_swap_util.c push_swap_moves.c sort_algo.c push_swap_util2.c \
		chunk_algo.c fake_chunk_algo.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_1)

$(NAME_2): $(OBJS)
	make bonus -C Libft/
	make -C Printf/
	ar rc $(NAME_2) $(OBJS)

$(NAME_1): $(NAME_2)
	cc push_swap.a Libft/libft.a Printf/libftprintf.a -o push_swap

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C Libft/
	make clean -C Printf/
	rm -f $(OBJS)

fclean: clean
	make fclean -C Libft/
	make fclean -C Printf/
	rm -f $(NAME_2)
	rm -f $(NAME_1)

re: fclean all

.PHONY: all clean fclean re