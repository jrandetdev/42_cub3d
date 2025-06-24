#ifndef	CUB3D_H
# define CUB3D_H

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

# ifndef BUFFERSIZE
# define BUFFERSIZE 20
# endif

typedef struct	s_main t_main;
typedef struct s_map t_map;
typedef struct s_color t_color;
typedef struct s_texture t_texture;
typedef struct	s_myimage t_myimage;
typedef struct s_vec2 t_vec2;
typedef struct s_keys t_keys;

/*------------------------------------ DEBUG ---------------------------------*/

void	print_grid(t_main *main);
void	init_debug(t_main *main);
void	print_wall(t_main *main);
void	draw_square(t_main *main, int start_x, int	start_y);

// MAP AND PARSING//

void	is_map_valid(t_main *main);
bool	parsing(t_main *main, char *file);
void	get_map_descritpion(t_main *main, char **file_content);
char	**get_file_content(t_main *main, int fd, char *file);

// RENDERING //
int		render_next_frame(t_main *main);
void	put_pixel_to_image(t_main *main, int x, int y, int color);
void	init_img(t_main *main);

size_t	count_map_height(char **map);

// ERROR HANDLING //
void	print_error_and_message(char *error_message);

// UTILS //
char	*get_next_line(int fd);

int		get_fd(t_main *main, char *s);

void	print_array(char **array);

// FREE FUNCTIONS //
void	safe_free_tab(void ***ptr);
void	free_string_array(char ***array);
void	free_ptr_and_set_to_null(char *ptr);
int		handle_destroy(t_main *main);
void	exit_cub3d(t_main *main, int error_status);

#endif