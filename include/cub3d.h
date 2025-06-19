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

# ifndef BUFFERSIZE
# define BUFFERSIZE 20
# endif

# define WIN_WIDTH 1250
# define WIN_HEIGHT 750

typedef struct	s_main t_main;

/*------------------------------------ DEBUG ---------------------------------*/

void	print_grid(t_main *main);
void	draw_square(void *mlx_ptr, void *mlx_win, int start_x, int	start_y);

/*------------------------------------ STRUCT --------------------------------*/
typedef struct	s_myimage
{
	int		size_line;
	int		bytespp;
	int		total_bytes;
	long	addr;
}	t_myimage;

typedef struct	s_main
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	int			debug;
	t_myimage	image;
}				t_main;

// MAP AND PARSING//
char	**build_map(int fd, char *file);

// ERROR HANDLING //
void	print_error_and_message(char *error_message);

// UTILS //
bool	parsing(t_main *main, char *file);
char	*get_next_line(int fd);
int		get_fd_for_reading(char *s);

// FREE FUNCTIONS //
void	free_ptr_and_set_to_null(char *ptr);
void	free_string_array(char ***array);

void	print_array(char **array);

#endif