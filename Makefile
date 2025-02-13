#Variables
NAME = push_swap

SRCS_DIR = ./srcs/
HEADER_DIR = ./header/
LIBFT = ./libft/libft.a

SRCS = $(SRCS_DIR)main.c $(SRCS_DIR)/moves/push_funcs.c $(SRCS_DIR)/moves/reverse_rotate_funcs.c \
       $(SRCS_DIR)/moves/rotate_funcs.c $(SRCS_DIR)/moves/swap_funcs.c \
       $(SRCS_DIR)/lst_funcs/args_parser.c $(SRCS_DIR)/lst_funcs/free_funcs.c \
       $(SRCS_DIR)/algo/algo_select_functions.c $(SRCS_DIR)/algo/move_cases.c \
       $(SRCS_DIR)/algo/move_same_sign.c $(SRCS_DIR)/algo/rotations.c $(SRCS_DIR)/algo/update_best.c \
       $(SRCS_DIR)/algo/num_utils.c $(SRCS_DIR)/algo/utils.c $(SRCS_DIR)/algo/utils2.c \
       $(SRCS_DIR)/algo/utils3.c \

OBJS = $(SRCS:.c=.o)

#Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(HEADER_DIR)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@


$(LIBFT):
	@echo "Compiling Libft..."
	@make -C ./libft

push_swap: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm -o push_swap

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make -C ./libft clean

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
