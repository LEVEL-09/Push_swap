NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putnbr.c ft_putstr.c hex.c ft_strlen.c ft_putchar.c ft_toupper.c hex_up.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@