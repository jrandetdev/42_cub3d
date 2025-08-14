/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:47:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 17:30:16 by jrandet          ###   ########.fr       */
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
# include "events.h"
# include "bonus_struct.h"
# include "dda.h"
# include "parsing.h"
# include "minimap.h"
# include "init.h"
# include "utils.h"
// # include "assets.h"

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

/*-------------------------------- PARSING -----------------------------------*/



/*-------------------------------- TEXTURE -----------------------------------*/



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

void		set_dda_params(t_main *main, t_dda *dda);
void		digital_differential_analyzer(t_main *main, t_dda *dda, int x);

/*-------------------------------- GAMELOOP ----------------------------------*/

int			key_handler(int key_code, t_main *main);

void		cast_rays(t_main *main);
void		init_external_events(t_main *main);
void		draw_texture(t_main *main, t_dda *dda, int x,
				t_texture texture);

size_t		count_map_height(char **map);
t_texture	get_corresp_texture(t_main *main, t_dda *dda);

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

float		get_vec2_norm(t_vector vec1, t_vector vec2);

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