
#    By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 13:31:29 by jlandeir          #+#    #+#              #
#    Updated: 2026/04/30 12:59:29 by jlandeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
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
       bench.c

OBJS = $(SRCS:%.c=%.o)

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

exec: re
	./$(NAME)

valgrind: $(NAME)
	@valgrind ./$(NAME)

.PHONY: all clean fclean re valgrind
