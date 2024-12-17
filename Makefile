NAME = libasm.a

SRC_DIR = srcs
OBJ_DIR = objs

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.s=.o))

EXEC = tester.result

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(@D)
	nasm -f elf64 $< -o $@

test: all
	gcc -Wall -Wextra -Werror main.c $(NAME) -o $(EXEC)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re test
