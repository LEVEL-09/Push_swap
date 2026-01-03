NAME = push_swap.a

SRCS = push_swap.c push_swap_util.c push_swap_moves.c sort_algo.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C Libft/
	make -C Printf/
	ar rc $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C Libft/
	make clean -C Printf/
	rm -f $(OBJS)

fclean: clean
	make fclean -C Libft/
	make fclean -C Printf/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re