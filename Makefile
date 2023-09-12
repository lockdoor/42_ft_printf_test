# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 10:31:40 by pnamnil           #+#    #+#              #
#    Updated: 2023/09/12 09:27:25 by pnamnil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRCS = main.c
OBJS = $(patsubst %.c, bin/%.o, $(SRCS))

LIBFTPRINTF_PATH = ../ft_printf
LIBFTPRINTF_NAME = libftprintf.a

LIBFT_PATH = $(LIBFTPRINTF_PATH)/libft

CC = cc
CFLEGS = -Wall -Werror -Wextra -I$(LIBFTPRINTF_PATH) -I$(LIBFT_PATH)

bin/%.o: %.c
	mkdir -p bin
	$(CC) $(CFLEGS) -c $< -o $@

all: $(NAME)
	./$(NAME)

$(NAME): lib_make $(OBJS)
	$(CC) $(CFLEGS) $(OBJS) $(LIBFTPRINTF_PATH)/$(LIBFTPRINTF_NAME) -o $(NAME)

lib_make:
	$(MAKE) -C $(LIBFTPRINTF_PATH)

l:
	leaks --atExit -- ./$(NAME)

v:
	valgrind ./$(NAME)

clean:
	rm -rf bin

fclean: clean
	$(MAKE) -C $(LIBFTPRINTF_PATH) fclean
	rm -f prog

re: fclean all
