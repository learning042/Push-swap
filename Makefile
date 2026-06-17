# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-v <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 17:30:25 by tpinto-v          #+#    #+#              #
#    Updated: 2026/06/17 16:27:13 by jlandeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ft_fprintf
LIBFT = $(LIBFT_DIR)/libftfprintf.a
GNL_DIR = get_next_line
GNL = $(GNL_DIR)/libget_next_line.a

NAME = push_swap
SRCS_DIR = srcs
INCLUDES = includes
SRCS = push_swap_utils.c \
       stacks.c \
       swap.c \
       push.c \
       rotate.c \
       rev_rotate.c \
       insertion_sort.c \
       radix_sort.c \
       bucket_sort.c \
       rev_insertion_sort.c \
       disorder.c \
       bench.c \
       parser.c \
       parser_utils.c \
       safe_atoi.c

SRC_MAIN = push_swap.c
NAME_BONUS = checker
SRCS_BONUS = checker.c

OBJS = $(SRCS:%.c=$(SRCS_DIR)/%.o)
OBJ_MAIN = $(SRCS_DIR)/$(SRC_MAIN:%.c=%.o)
OBJS_BONUS = $(SRCS_DIR)/$(SRCS_BONUS:%.c=%.o)

MAKE_LIBFT = $(MAKE) -C $(LIBFT_DIR)
MAKE_GNL = $(MAKE) -C $(GNL_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(OBJ_MAIN) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(INCLUDES) -L$(LIBFT_DIR) $(OBJS) $(OBJ_MAIN) -o $(NAME) -lftfprintf

$(LIBFT):
	$(MAKE_LIBFT)

$(GNL):
	$(MAKE_GNL)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ_MAIN)
	rm -rf $(OBJS_BONUS)
	$(MAKE_LIBFT) clean
	$(MAKE_GNL) clean
	
fclean: clean
	rm -rf $(NAME) 
	rm -rf $(NAME_BONUS)
	$(MAKE_LIBFT) fclean
	$(MAKE_GNL) fclean

re: fclean all bonus

bonus: $(NAME_BONUS)

$(NAME_BONUS):	$(OBJS) $(OBJS_BONUS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(GNL) -I$(INCLUDES) -L$(LIBFT_DIR) -L$(GNL_DIR) $(OBJS) $(OBJS_BONUS) -o $(NAME_BONUS) -lftfprintf -lget_next_line

.PHONY: all clean fclean re bonus
