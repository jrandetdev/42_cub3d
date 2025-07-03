#ifndef	CUB3D_H
# define CUB3D_H

# define _USE_MATH_DEFINES

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "libft.h"
#include "keycode.h"
#include "struct.h"
#include <mlx.h>
#include <math.h>

# ifndef BUFFERSIZE
# define BUFFERSIZE 20
# endif

# define TILE_SIZE 1
# ifndef M_PI
# define M_PI 3.14159265358979323846
# endif

typedef struct	s_main t_main;
typedef struct	s_map t_map;
typedef struct	s_texture t_texture;
typedef struct	s_myimage t_myimage;
typedef struct	s_vec2 t_vec2;
typedef struct	s_keys t_keys;

/*------------------------------------ DEBUG ---------------------------------*/


void	init_debug(t_main *main);

// MAP AND PARSING//

bool	is_dir(char *file_relative_path);
bool	parsing(t_main *main, char *file);
bool	cub_extension_is_valid(char	*s, int len);
bool	xmp_extension_is_valid(char	*s, int len);

char	*max_strdup(const char *s1, int max_size);
char	**get_file_content(t_main *main, int fd, char *file);

void	is_map_valid(t_main *main);
void	parse_map_elements(t_main *main);
void	get_map_descritpion(t_main *main);
void	extract_colour(t_main *main, char *id, char *info);
void	extract_texture(t_main *main, char *id, char *xpm_f);
void	validate_colour(t_main *main, char **splitted_colours);
bool	find_player_position(t_main *main, int *x, int *y, int *player);

// MINIMAP //
void	print_fov(t_main *main);
void	print_grid(t_main *main);
void	draw_player(t_main *main);
void	print_minifov(t_main *main);
void	print_minimap(t_main *main);
void	print_obstacles(t_main *main);
void	mini_dda(t_main *main, double dst_x, double dst_y);

// RENDERING //
int		render_next_frame(t_main *main);
void	put_pixel_to_image(t_main *main, int x, int y, int colour);
void	init_img(t_main *main);

size_t	count_map_height(char **map);

// ERROR HANDLING //
void	print_error_and_message(char *error_message);

// UTILS //
char	*get_next_line(int fd);
int		has_new_line(char *buffer);
char	*join_and_free(char *line, char *tmp2);
void 	normalize_angle(double *angle);

void	digital_differential_analyzer(t_main *main, double dst_x, double dst_y);
void	ft_strcpy(char *dest, char *src, int start, int end);

size_t	string_array_len(char **str);

int		get_fd(t_main *main, char *file_relative_path);

void	print_array(char **array);

// FREE FUNCTIONS //
void	safe_free_tab(void ***ptr);
void	free_string_array(char ***array);
void	free_all_pointer_arrays(t_main *main);
void	free_mlx_pointers(t_main *main);
void	free_ptr_and_set_to_null(char *ptr);
int		handle_destroy(t_main *main);
void	exit_cub3d(t_main *main, char *error_message);

#endif