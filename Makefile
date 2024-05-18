NAME		= push_swap
BONUS		= checker
CHECKER_DIR = checker_bonus/src/
MAN_DIR 	= mandatory/src/

SRCS		= $(MAN_DIR)basic_utils.c $(MAN_DIR)operations.c $(MAN_DIR)push_swap.c $(MAN_DIR)sort_stack.c \
				$(MAN_DIR)init_stack.c $(MAN_DIR)complex_sort.c $(MAN_DIR)calculate_moves.c $(MAN_DIR)stack_utils.c
BONUS_SRCS	= $(CHECKER_DIR)checker_bonus.c $(CHECKER_DIR)execute_operations_bonus.c $(CHECKER_DIR)operations_bonus.c \
				$(CHECKER_DIR)stack_utils_bonus.c $(CHECKER_DIR)utils_bonus.c

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -g

$(NAME): $(LIBFT) $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) all bonus -s -C $(LIBFT_DIR)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_SRCS)
	@$(CC) $(CFLAGS) $(BONUS_SRCS) -L$(LIBFT_DIR) -lft -o $(BONUS)

clean:
	make -s -C $(LIBFT_DIR) clean

fclean: clean
	make -s -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus