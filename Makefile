NAME			=			cub3d

DIR_BUILD		=			./build
DIR_INCLUDE		=			./include
DIR_SRC			=			./src

MLX_PATH		:=			./libs/minilibx-linux/
MLX_NAME		:=			libmlx.a
MLX				:=			$(MLX_PATH)$(MLX_NAME)

LIBFT_PATH		:=			./libs/libft/
LIBFT_NAME		:=			libft.a
LIBFT			:=			$(LIBFT_PATH)$(LIBFT_NAME)

SOURCES			:=			main.c

SOURCE_NAME		:=			$(basename $(SOURCES))
OBJECTS			:= 			$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(SOURCE_NAME)))
DEPS			:=			$(OBJECTS:.o=.d)

INC_FLAGS		:=			-I $(DIR_INCLUDE) -I $(LIBFT_PATH) -I $(MLX_PATH)

LIBRARY_PATHS	:=			-L$(LIBFT_PATH) -L$(MLX_PATH)
LIBRARIES		:=			-lft -lmlx -lX11 -lXext -lm -lz

CC				= cc
CFLAGS			= -Wall -Werror -Wextra $(INC_FLAGS) -g -MMD -MP
ifeq ($(UNAME), Darwin)
	CFLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -sC $(MLX_PATH) > /dev/null 2>&1
	@make -sC $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBRARY_PATHS) $(LIBRARIES) -o $@
	@echo "Cube3d: Make succesfull, can execute ./cub3d"

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(DIR_BUILD):
	@mkdir -p $@

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@rm -rf $(DIR_BUILD)

fclean: clean
	@echo "Cube3d: fclean complete."
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)

#example to base myself off of
#cc -Wall -Werror -Wextra jojo.c -L library -l link the libraries -o jojo