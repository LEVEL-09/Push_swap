NAME_1 = push_swap

NAME_2 = checker

SRCS = push_swap.c push_swap_util.c push_swap_moves.c sort_algo.c push_swap_util2.c \
		chunk_algo.c fake_chunk_algo.c

SRCB = bonus/checker_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
		bonus/checker_util_bonus.c bonus/checker_util2_bonus.c

LSRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

PSRCS = ft_printf.c ft_putnbr.c ft_putstr.c hex.c ft_strlen.c ft_putchar.c ft_toupper.c hex_up.c

OBJS = $(SRCS:.c=.o)

OBJB = $(SRCB:.c=.o)

LOBJS = $(addprefix Libft/, $(LSRCS:.c=.o))

POBJS = $(addprefix Printf/, $(PSRCS:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_1)

bonus: $(NAME_2)

$(NAME_2): $(OBJB) $(LOBJS) $(POBJS)
	make -C Printf/
	make bonus -C Libft/
	$(CC) $(OBJB) Libft/libft.a Printf/libftprintf.a -o $(NAME_2)

$(NAME_1): $(OBJS) $(LOBJS) $(POBJS)
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

.PHONY: all clean fclean re bonus