NAME = push_swap

INC = ./inc/
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft/
OBJ_DIR = obj/
SRC_DIR = src/

CC = gcc
FLAGS = -Wall -Werror -Wextra -g -I $(INC)


COMMANDS_DIR = $(SRC_DIR)/commands/swap.c \
						$(SRC_DIR)/commands/rotate.c \
						$(SRC_DIR)/commands/rev_rotate.c \
						$(SRC_DIR)/commands/push.c\
						$(SRC_DIR)/commands/sort_three.c\
						$(SRC_DIR)/commands/sort_stacks.c
PUSH_SWAP_DIR = $(addprefix $(SRC_DIR),	push_swap.c\
										split.c\
										stack_init.c\
										stack_utils.c\
										info_nodes_a_to_b.c\
										info_nodes_b_to_a.c\
										handle_errors.c	)

SRCS = $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

OBJS	:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

start:
	make all

libft:
	make -C ./libft

clean:
	rm -f $(OBJS)
	make clean -C ./libft
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
re: fclean all

.PHONY: all clean fclean re





