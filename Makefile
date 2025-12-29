NAME = push_swap.a

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C Libft/
	ar rc $(NAME) $(OBJS)

%.o: %.c push_swap.a
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C Libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C Libft/
	rm -f $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re