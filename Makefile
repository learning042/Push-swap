# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-v <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 17:30:25 by tpinto-v          #+#    #+#              #
#    Updated: 2026/06/12 17:33:15 by tpinto-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libftprintf.a

NAME = push_swap
SRCS = push_swap_utils.c \
       swap.c \
       push.c \
       rotate.c \
       rev_rotate.c \
       insertion_sort.c \
       push_swap.c \
       radix_sort.c \
       checker.c \
       bucket_sort.c \
       rev_insertion_sort.c \
       disorder.c \
       bench.c \
       parser.c

OBJS = $(SRCS:%.c=%.o)2

MAKE_LIBFT = $(MAKE) -C $(LIBFT_DIR)

MAIN = main.c

EXEC = $(basename $(MAIN))

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -L$(LIBFT_DIR) $(OBJS) -o $(NAME) -lftprintf

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE_LIBFT) clean
	
fclean: clean
	rm -rf $(NAME) 
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
