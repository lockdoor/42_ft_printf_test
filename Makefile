# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 10:31:40 by pnamnil           #+#    #+#              #
#    Updated: 2023/09/07 12:07:44 by pnamnil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRCS = main.c
OBJS = $(patsubst %.c, bin/%.o, $(SRCS))

LIBFTPRINTF_PATH = ../ft_printf
LIBFTPRINTF_NAME = libftprintf.a

LIBFT_PATH = $(LIBFTPRINTF_PATH)/libft

CC = cc
# CFLEGS = -Wall -Werror -Wextra -I$(LIBFTPRINTF_PATH) -I$(LIBFTPRINTF_PATH)/libft
CFLEGS = -Wall -Werror -Wextra -I$(LIBFTPRINTF_PATH) -I$(LIBFT_PATH)

bin/%.o: %.c
	mkdir -p bin
	$(CC) $(CFLEGS) -c $< -o $@

all: $(NAME)
	./$(NAME)

$(NAME): lib_make $(OBJS)
# $(CC) $(CFLEGS) $(OBJS) -L$(LIBFTPRINTF_NAME) -lftprintf -o $(NAME)
	$(CC) $(CFLEGS) $(OBJS) $(LIBFTPRINTF_PATH)/$(LIBFTPRINTF_NAME) -o $(NAME)

lib_make:
	$(MAKE) -C $(LIBFTPRINTF_PATH)

clean:
	rm -rf bin

fclean: clean
	$(MAKE) -C $(LIBFTPRINTF_PATH) fclean
	rm -f prog

re: fclean all
