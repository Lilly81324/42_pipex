CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
SRC_FILES = \
aa_main.c \
ft_free_char_arr_arr.c \
ft_get_path.c \
ft_get_arg_for_execve.c \
ft_space_bef.c \
ft_space_aft.c \
ft_launcher.c \
ft_first_cmd.c \
ft_first_cmd_pipe.c \
ft_fork_one.c \
ft_scnd_cmd.c \
ft_fork_two.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)
NAME = pipex

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_FILES)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re