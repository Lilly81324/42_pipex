CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
SRC_FILES = \
aa_main.c \
ft_launcher.c \
ft_free_char_arr_arr.c \
ft_get_path.c \
ft_get_arg_for_execve.c \
ft_space_bef.c \
ft_space_aft.c \
ft_prepare_first.c \
ft_prepare_sec.c \
ft_stdin_to_infile.c \
ft_stdin_to_pipe.c \
ft_stdout_to_outfile.c \
ft_stdout_to_pipe.c
BNS_SRC_FILES = \
aa_main_bonus.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)
BNS_OBJ_FILES = $(BNS_SRC_FILES:%.c=%.o)
NAME = pipex

all: $(NAME)

bonus: .bonus_done

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.bonus_done: $(BNS_OBJ_FILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(BNS_OBJ_FILES) -o $(NAME) $(LIBFT_LIB)
	touch .bonus_done

$(NAME): $(OBJ_FILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_FILES)
	rm -f $(BNS_OBJ_FILES)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f .bonus_done

re: fclean all

PHONY: all clean fclean re bonus