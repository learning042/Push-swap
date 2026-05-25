
#    By: jlandeir <jlandeir@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 13:31:29 by jlandeir          #+#    #+#              #
#    Updated: 2026/04/30 12:59:29 by jlandeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS = push_swap_utils.c \
       swap.c \
       push.c \
       rotate.c \
       rev_rotate.c \
       insertion_sort.c \
       ft_atoi.c \
       push_swap.c \
       checker.c

OBJS = $(SRCS:%.c=%.o)

MAIN = main.c

EXEC = $(basename $(MAIN))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	
fclean: clean
	rm -f $(NAME)

re: fclean all

exec: re
	./$(NAME)

valgrind: $(NAME)
	@valgrind ./$(NAME)

.PHONY: all clean fclean re valgrind
