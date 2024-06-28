NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCS = sorting_utils.c \
		algo.c \
		parsing.c \
		lst_management.c \
		add_fd.c \
		ft_split.c \
		operations.c \
		push_swap_sorts.c \
		push_swap_utils.c \
		push_swap.c \
		string_operations.c \
		split_utils.c \

OBJS = $(SRCS:.c=.o)
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@make clean
	

clean : 
	@rm -rf $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.SECONDARY : $(OBJS)
