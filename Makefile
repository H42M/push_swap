# **************************************************************************** #

#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeorges <hgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 13:04:39 by hgeorges          #+#    #+#              #
#    Updated: 2025/12/04 13:04:42 by hgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c parser.c parser_utils.c parse_flags.c parse_input_validation.c \
       printf/ft_printf.c printf/ft_printf_utils.c \
       utils/ft_split.c utils/string_utils.c \
       list_basic.c list_utils.c stack_init.c stack_utils.c \
       operations.c algo_simple.c algo_medium.c algo_medium_utils.c algo_complex.c algo_complex_index_mapping.c \
       algo_adaptive.c algo_utils.c strategy.c benchmark.c error.c \
       push_swap_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re