NAME			=			cub3d
CC				=			cc

UNAME			=			$(shell uname)

DIR_BUILD		=			./build
DIR_INCLUDE		=			./include

MLX_PATH_UNIX	:=			./libs/minilibx-linux/
MLX_NAME_UNIX	:=			libmlx.a
MLX_PATH_OSX	:=			./libs/minilibx-macos
MLX_NAME_OSX	:=			libmlx.dylib

LIBFT_PATH		:=			./libs/libft/
LIBFT_NAME		:=			libft.a
LIBFT			:=			$(LIBFT_PATH)$(LIBFT_NAME)

ifeq ($(UNAME), Darwin)
	MLX_PATH	= $(MLX_PATH_OSX)
	MLX_NAME	= $(MLX_NAME_OSX)
	LIBRARIES	= -lft -lmlx -framework Metal -framework MetalKit -framework AppKit -lz
else ifeq ($(UNAME), Linux)
	MLX_PATH	= $(MLX_PATH_UNIX)
	MLX_NAME	= $(MLX_NAME_UNIX)
	LIBRARIES	= -lft -lmlx -lX11 -lXext -lm -lz
endif

MLX = $(MLX_PATH)$(MLX_NAME)

#------------ SOURCES ------------#

DIR_MAIN		=			./src/main
SRC_MAIN		=			main.c \
							exit_and_error.c \
							free_utils.c
MAIN			=			$(addprefix $(DIR_MAIN)/, $(SRC_MAIN))

DIR_PARSING		=			./src/parsing
SRC_PARCING		=			parse_entire_map.c\
							map_building.c
PARCING			=			$(addprefix $(DIR_PARSING)/, $(SRC_PARCING))

DIR_UTILS		=			./src/utils
SRC_UTILS		=			get_next_line.c
UTILS			=			$(addprefix $(DIR_UTILS)/, $(SRC_UTILS))

DIR_DEBUG		=			./src/debug
SRC_DEBUG		=			debug.c \
							print_grid.c \
							square.c
DEBUG 			=			$(addprefix $(DIR_DEBUG)/, $(SRC_DEBUG))

SOURCES			=			$(MAIN) $(PARCING) $(UTILS) $(DEBUG)
vpath %.c		 			$(DIR_MAIN) $(DIR_PARSING) $(DIR_UTILS) $(DIR_DEBUG)

SOURCE_NAME		:=			$(basename $(SOURCES))
OBJECTS			:= 			$(addprefix $(DIR_BUILD)/, $(notdir $(SOURCES:.c=.o)))
DEPS			:=			$(OBJECTS:.o=.d)

CFLAGS			=			-Wall -Werror -Wextra $(INC_FLAGS) -g -MMD -MP
INC_FLAGS		:=			-I $(DIR_INCLUDE) -I $(LIBFT_PATH) -I $(MLX_PATH)
LIBRARY_PATHS	:=			-L$(LIBFT_PATH) -L$(MLX_PATH)

#------------- RULES -------------#

all: $(NAME)

$(NAME): $(OBJECTS)
	make -sC $(MLX_PATH) > /dev/null 2>&1
	make -sC $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBRARY_PATHS) $(LIBRARIES) -o $@
	@cp $(MLX_PATH)/libmlx.dylib .
	echo "Cube3d: Make succesfull, can execute ./cub3d"

$(DIR_BUILD)/%.o: %.c | $(DIR_BUILD)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(DIR_BUILD):
	mkdir -p $@

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH) > /dev/null 2>&1
	rm -rf $(DIR_BUILD)
	rm -rf libmlx.dylib

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)
	echo "Cube3d: fclean complete."

re: fclean all

.PHONY: all clean fclean re

.SILENT:

-include $(DEPS)

#example to base myself off of
#cc -Wall -Werror -Wextra jojo.c -L library -l link the libraries -o jojo