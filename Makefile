NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -Iincludes

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= main.c \
			  stack_init.c \
			  stack_utils.c \
			  stack_utils_2.c \
			  ops_swap.c \
			  ops_push.c \
			  ops_rotate.c \
			  ops_rev_rotate.c \
			  sort.c \
			  lis.c \
			  init_a.c \
			  init_b.c \
			  utils_atol.c \
			  utils_split.c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
