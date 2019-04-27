# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgigi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 13:08:04 by lgigi             #+#    #+#              #
#    Updated: 2019/04/26 13:08:45 by lgigi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = ft_ltoa.c \
	  ft_print_scp.c \
	  ft_printf_diox.c \
	  ft_utoa.c \
	  ft_printf.c \
	  ft_parse.c \
	  ft_print_fl.c \
	  utils.c \
	  checks.c \
	  buffer.c \

LIB_FILES = ft_atoi.c \
		 ft_itoa.c \
		 ft_strchr.c \
		 ft_strdup.c \
		 ft_strlen.c \
		 ft_strnew.c \
		 ft_strcpy.c \
		 ft_bzero.c \
		 ft_isdigit.c \
		 ft_isalpha.c \

LIB_SRC = $(addprefix ./libft/, $(LIB_FILES))

OBJ = $(SRC:.c=.o)
OBJ_LFT = $(LIB_FILES:.c=.o)
LFINC = libft/

all: $(NAME)

$(NAME):
	$(CC) -c $(LIB_SRC) $(SRC) -I $(LFINC)
	ar rc $(NAME) $(OBJ_LFT) $(OBJ) 
	ranlib $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_LFT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: re
	@$(CC)  main.c -I libft/  -L. -lftprintf -o test
	@./test

.PHONY: all fclean clean re test
