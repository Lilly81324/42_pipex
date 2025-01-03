CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

BNS_FILES = $(wildcard ft_lst*.o)
SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:%.c=%.o)
NON_BNS_OBJ_FILES = $(filter-out ft_lst%.o, $(OBJ_FILES))

all: $(NAME)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile all objects into final file
$(NAME): $(NON_BNS_OBJ_FILES)
	ar rcs $(NAME) $(NON_BNS_OBJ_FILES)

bonus: $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
