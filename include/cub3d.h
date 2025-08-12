/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:47:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/12 16:36:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _USE_MATH_DEFINES
# define GAME_NAME "CUBE3D"

# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "libft.h"
# include "bonus.h"
# include "struct.h"
# include "parameter.h"
# include "bonus_struct.h"

# define RED	"\x1b[31;1m"
# define GREEN	"\x1b[32;1m"
# define YELLOW	"\x1b[33;1m"
# define RESET	"\x1b[0m"

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef BUFFERSIZE
#  define BUFFERSIZE 20
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_texture	t_texture;

/*-------------------------------- PARSING -----------------------------------*/

void		is_dir(t_main *main, char *file_relative_path);
bool		parsing(t_main *main, char *file);
bool		cub_extension_is_valid(char	*s, int len);
bool		xmp_extension_is_valid(char	*s, int len);
bool		validate_colour(t_main *main, char **splitted_colours);
bool		find_player_position(t_main *main, int *x, int *y, int *player);

char		*max_strdup(const char *s1, int max_size);
char		**get_file_content(t_main *main, int fd, char *file);

void		is_map_valid(t_main *main);
void		parse_map_elements(t_main *main, char **file_content);
void		get_map_descritpion(t_main *main, char **file_content);
void		load_personal_textures(t_main *main);
void		extract_colour(t_main *main, char *id, char *info);
void		extract_texture(t_main *main, char *id, char *xpm_f);
void		get_texture_data(t_main *main, t_texture *direc, char *xpm_file);
void		check_and_get_texture(t_main *main, t_texture *pannel,
				char *filename);

/*-------------------------------- MINIMAP -----------------------------------*/

void		print_fov(t_main *main);
void		print_grid(t_main *main);
void		draw_player(t_main *main);
void		init_minimap(t_main *main);
void		print_minifov(t_main *main);
void		print_minimap(t_main *main);
void		mini_raycasting(t_main *main);
void		print_minimap_base(t_main *main);

t_vec2		mini_dda(t_main *main, float dst_x, float dst_y);

/*------------------------------- RENDERING ----------------------------------*/

int			game_loop(t_main *main);

void		init_img(t_main *main);
void		player_movement(t_main *main);
void		put_pixel_to_image(t_main *main, int x, int y, int colour);
void		valid_next_movement_up(t_main *main, float next_x, float next_y);
void		valid_next_movement_down(t_main *main, float next_x,
				float next_y);
void		valid_next_movement_left(t_main *main, float next_x,
				float next_y);
void		valid_next_movement_right(t_main *main, float next_x,
				float next_y);

/*-------------------------------- GAMELOOP ----------------------------------*/

int			key_handler(int key_code, t_main *main);

void		cast_rays(t_main *main);
void		init_external_events(t_main *main);
void		draw_texture(t_main *main, t_dda_struct *dda_struct, int x,
				t_texture texture);

size_t		count_map_height(char **map);
t_texture	get_corresp_texture(t_main *main, t_dda_struct *dda_struct);

/*---------------------------- ERROR HANDELING -------------------------------*/

void		print_error();
void		print_error_syscall(t_main *main, char *error_message);
void		print_error_message(t_main *main, char *error_message);
	/*--------------------------------- UTILS ------------------------------------*/

int			has_new_line(char *buffer);
int			get_fd(t_main *main, char *file_relative_path);

char		*get_next_line(int fd);
char		*join_and_free(char *line, char *tmp2);

void		print_array(char **array);
void		normalize_angle(float *angle);
void		calcule_constants(t_main *main);
void		ft_strcpy(char *dest, char *src, int start, int end);
void		digital_differential_analyzer(t_main *main,
				t_dda_struct *dda_struct);

float		get_vector_norm(t_vec2 vec1, t_vec2 vec2);

size_t		string_array_len(char **str);

/*----------------------------- FREE FUNCTIONS -------------------------------*/

int			handle_destroy(t_main *main);

void		safe_free_tab(void ***ptr);
void		free_mlx_pointers(t_main *main);
void		free_string_array(char ***array);
void		free_ptr_and_set_to_null(char *ptr);
void		free_all_pointer_arrays(t_main *main);
void		exit_cub3d(t_main *main, int exit_code);

#endif