GREEN = \033[0;32m
RESET = \033[0m

NAME			=			cub3D
CC				=			cc

UNAME			=			$(shell uname)

DIR_BUILD		=			./build
DIR_INCLUDE		=			./include

INCLUDE_SUBDIRS	=			$(DIR_INCLUDE)/bonus \
							$(DIR_INCLUDE)/core \
							$(DIR_INCLUDE)/game \
							$(DIR_INCLUDE)/graphics \
							$(DIR_INCLUDE)/parsing \
							$(DIR_INCLUDE)/utils

MLX_PATH_UNIX	:=			./libs/minilibx-linux/
MLX_NAME_UNIX	:=			libmlx.a
MLX_PATH_OSX	:=			./libs/minilibx-macos/
MLX_NAME_OSX	:=			libmlx.a

LIBFT_PATH		:=			./libs/libft/
LIBFT_NAME		:=			libft.a
LIBFT			:=			$(LIBFT_PATH)$(LIBFT_NAME)

ifeq ($(UNAME), Darwin)
	MLX_PATH	= $(MLX_PATH_OSX)
	MLX_NAME	= $(MLX_NAME_OSX)
	LIBRARIES	= -fsanitize=address -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
else ifeq ($(UNAME), Linux)
	MLX_PATH	= $(MLX_PATH_UNIX)
	MLX_NAME	= $(MLX_NAME_UNIX)
	LIBRARIES	= -lft -lmlx -lX11 -lXext -lm -lz -lXfixes
endif

MLX = $(MLX_PATH)$(MLX_NAME)

#------------ SOURCES ------------#

DIR_MAIN		=			./src
MAIN_SRC		=			$(addprefix $(DIR_MAIN)/, main.c)

DIR_INIT		=			./src/init
SRC_INIT		=			init_all.c \
							init_args.c \
							init_cub.c \
							init_img.c \
							init_mlx.c
INIT		=				$(addprefix $(DIR_INIT)/, $(SRC_INIT))

DIR_PARSING		=			./src/parsing
SRC_PARSING		=			parsing.c \
							check_if_map_is_valid.c \
							flood_fill.c \
							get_fd.c \
							check_if_dir.c \
							init_player.c \
							check_for_tabs.c \
							extract_texture.c \
							get_map_dimensions.c \
							get_texture_data.c \
							load_personal_texture.c \
							extract_colour.c \
							extract_file_content.c \
							extract_map_from_file.c \
							validate_colour.c \
							parse_texture_and_colour.c \
							check_extension_and_file_type.c
PARSING			=			$(addprefix $(DIR_PARSING)/, $(SRC_PARSING))


DIR_HANDLE_TEXTURES		=	./src/handle_textures
SRC_HANDLE_TEXTURES		=	draw_walls.c \
							draw_floor_and_ceiling.c \
							get_texture.c
HANDLE_TEXTURES			=	$(addprefix $(DIR_HANDLE_TEXTURES)/, $(SRC_HANDLE_TEXTURES))

DIR_GAMELOOP	=			./src/gameloop
SRC_GAMELOOP	=			game_loop.c
GAMELOOP		=			$(addprefix $(DIR_GAMELOOP)/, $(SRC_GAMELOOP))

DIR_PLAYER		=			./src/player
SRC_PLAYER		=			player_movement.c \
							player_rotation.c \
							validate_forward_and_backward.c \
							validate_right_and_left.c
PLAYER			=			$(addprefix $(DIR_PLAYER)/, $(SRC_PLAYER))

DIR_EVENTS		=			./src/events
SRC_EVENTS		=			external_events.c
EVENTS			=			$(addprefix $(DIR_EVENTS)/, $(SRC_EVENTS))


DIR_MINIMAP		=			./src/minimap
SRC_MINIMAP		=			draw_player.c \
							minimap.c \
							print_minimap.c \
							print_grid.c \
							minifov.c \
							mini_dda.c
MINIMAP 		=			$(addprefix $(DIR_MINIMAP)/, $(SRC_MINIMAP))

DIR_BONUS		=			./src/bonus
SRC_BONUS		=			door.c \
							fps_counter.c \
							destroy_threads.c \
							threads_routine.c \
							create_and_manage_threads.c
BONUS			=			$(addprefix $(DIR_BONUS)/, $(SRC_BONUS))

DIR_RENDER_IMG	=			./src/render_img
SRC_RENDER_IMG	=			render.c \
							dda_algorithm.c \
							compute_dda_params.c \
							put_pixel_to_image.c
RENDER_IMG 		=			$(addprefix $(DIR_RENDER_IMG)/, $(SRC_RENDER_IMG))


# DIR_MENU		=			./src/menu
# SRC_MENU		=			main_menu.c \
# 							menu_utils.c \
# 							mouse_menu.c \
# 							pause_menu.c \
# 							option_menu.c \
# 							print_debug_menu.c \
# 							print_menu_title.c \
# 							print_correct_menu.c \
# 							print_menu_section.c
# MENU			=			$(addprefix $(DIR_MENU)/, $(SRC_MENU))

DIR_UTILS		=			./src/utils
SRC_UTILS		=			vector.c \
							string_array_len.c \
							exit_cub3d.c \
							get_next_line.c \
							copy_map.c \
							get_next_line_utils.c \
							is_only_spaces.c \
							max_strdup.c \
							null_terminate_line.c \
							error_handling.c \
							free_utils.c
UTILS			=			$(addprefix $(DIR_UTILS)/, $(SRC_UTILS))

SOURCES			=			$(MAIN_SRC) $(PARSING) $(UTILS) $(DEBUG) $(EVENTS) \
							$(GAMELOOP) $(MINIMAP) $(RENDER_IMG) $(MENU) $(BONUS) \
							$(INIT) $(HANDLE_TEXTURES) $(PLAYER)
vpath %.c		 			$(DIR_MAIN) $(DIR_PARSING) $(DIR_UTILS) $(DIR_DEBUG) $(DIR_EVENTS) $(DIR_GAMELOOP) $(DIR_GAMELOOP) $(DIR_MINIMAP) $(DIR_RENDER_IMG) $(DIR_MENU) $(DIR_BONUS) $(DIR_INIT) $(DIR_HANDLE_TEXTURES) $(DIR_PLAYER)

OBJECTS			:= 			$(addprefix $(DIR_BUILD)/, $(notdir $(SOURCES:.c=.o)))
DEPS			:=			$(OBJECTS:.o=.d)

CFLAGS			=			-Wall -Werror -Wextra $(INC_FLAGS) -g -MMD -MP -O3
INC_FLAGS		:=			$(addprefix -I , $(INCLUDE_SUBDIRS)) \
							-I $(LIBFT_PATH) \
							-I $(MLX_PATH)
LIBRARY_PATHS	:=			-L$(LIBFT_PATH) -L$(MLX_PATH)

#------------- RULES -------------#

all: $(NAME)

$(NAME):  $(OBJECTS) | $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBRARY_PATHS) $(LIBRARIES) -o $@
	@echo "$(GREEN)Cube3d: Make successful, can execute ./cub3d$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(MLX):
	@make -C $(MLX_PATH) 2> /dev/null

$(DIR_BUILD)/%.o: %.c | $(DIR_BUILD)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(DIR_BUILD):
	@mkdir -p $@

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH) 2>/dev/null || true
	@rm -rf $(DIR_BUILD)
	@rm -f libmlx.dylib

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(GREEN)Cube3d: fclean complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:

-include $(DEPS)