CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_ltoa.c \
	  ft_pr_itoa_base.c \
	  ft_pr_ltoa_base.c \
	  ft_print_scp.c \
	  ft_printf_diox.c \
	  ft_utoa.c \
	  print.c \
	  ft_parse.c \

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(OBJECTS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -I libft/

$(NAME): $(OBJECTS)
	@make -C libft
	@ar rc $(NAME) $(OBJECTS) libft/*.o
	@ranlib libftprintf.a

clean:
	@make clean -C libft
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

test: re
	@$(CC) $(CFLAGS) main.c -I libft/  -L. -lftprintf -o test
	@./test

.PHONY: all fclean clean re