NAME = ft_ls

SRC_PATH = src/
OBJ_PATH  = obj/
LIBFT = libft/
INC = -I ./inc/ -I $(LIBFT)inc/
CFLAGS = -Wall -Werror -Wextra

SRC_NAME =  ft_ls.c \
			print.c \
			flags.c \
			new_file.c \
			sort.c \
			recursive.c\
			supp.c \
			read.c \
			errors.c \
			new_dir.c \
			by_ascii.c \
			by_time.c \

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) $(INC) -L $(LIBFT) -lft -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	@gcc -c $(CFLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@make -C $(LIBFT)/ clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files \033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make -C $(LIBFT)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re