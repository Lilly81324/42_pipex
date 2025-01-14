CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
SRC_FILES = \
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
SRC_MAIN = aa_main.c
OBJ_MAIN = $(SRC_MAIN:%.c=%.o)
BNS_SRC_FILES = \
aa_main_bonus.c \
ft_first_cmd_bonus.c \
ft_handle_first_bonus.c \
ft_handle_mid_bonus.c \
ft handle_last_bonus.c \
ft_last_cmd_bonus.c \
ft_mid_cmd_bonus.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)
BNS_OBJ_FILES = $(BNS_SRC_FILES:%.c=%.o)
NAME = pipex

all: $(NAME)

bonus: .bonus_done

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
 
.bonus_done: $(BNS_OBJ_FILES) $(LIBFT_LIB) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(BNS_OBJ_FILES) $(OBJ_FILES) $(LIBFT_LIB) -o $(NAME) 
	touch .bonus_done

$(NAME): $(OBJ_FILES) $(LIBFT_LIB) $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(OBJ_MAIN) $(LIBFT_LIB) -o $(NAME)

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