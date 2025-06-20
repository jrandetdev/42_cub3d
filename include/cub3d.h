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
#include <mlx.h>

# ifndef BUFFERSIZE
# define BUFFERSIZE 20
# endif

typedef struct	s_main t_main;

/*------------------------------------ DEBUG ---------------------------------*/

void	print_grid(t_main *main);
void	draw_square(void *mlx_ptr, void *mlx_win, int start_x, int	start_y);

/*------------------------------------ STRUCT --------------------------------*/
typedef struct	s_myimage
{
	void	*data_img;
	void	*addr;
	int		size_line;
	int		bitspp;
	int		bytespp;
	int		total_bytes;
	int		pixels_per_line;
	int		endian;
}	t_myimage;

typedef struct s_texture
{
	void	*texture;
	int		x_size;
	int		y_size;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct	s_main
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	int			debug;
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	t_color		c;
	t_color		f;
	t_myimage	image;
}				t_main;

// MAP AND PARSING//

bool	is_map_valid(char **map);
bool	parsing(t_main *main, char *file);
void	get_map_descritpion(t_main *main);
void	build_map(t_main *main, int fd, char *file);

size_t	count_map_height(char **map);

// ERROR HANDLING //
void	print_error_and_message(char *error_message);

// UTILS //
char	*get_next_line(int fd);

int		get_fd(t_main *main, char *s);

void	init_img(t_main *main);
void	print_array(char **array);

// FREE FUNCTIONS //
void	safe_free_tab(void ***ptr);
void	free_string_array(char ***array);
void	free_ptr_and_set_to_null(char *ptr);
void	exit_cub3d(t_main *main, int error_status);

#endif