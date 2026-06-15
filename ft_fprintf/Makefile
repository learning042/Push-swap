# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 13:31:29 by jlandeir          #+#    #+#              #
#    Updated: 2026/06/15 13:40:49 by jlandeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

NAME = libftfprintf.a
SRCS = ft_fprintf.c \
       ft_str_int.c \
       ft_aux_ptr.c \

OBJS = $(SRCS:%.c=%.o)
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
RM = rm -f
MAIN = main.c

EXEC = $(basename $(MAIN))

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

$(EXEC): all
	$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(EXEC)

cleanexec: $(EXEC)
	[ -f $(EXEC) ] && $(RM) $(EXEC)

run: $(EXEC)
	@./$(EXEC)

valgrind: $(EXEC)
	@valgrind ./$(EXEC)

.PHONY: all clean fclean re cleanexec run valgrind
