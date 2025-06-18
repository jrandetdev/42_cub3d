#ifndef	CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>
#include "libft.h"

# define WIN_WIDTH 2000
# define WIN_HEIGHT 1500

/*---------------------------------- KEYCODE ---------------------------------*/

# define W 17
# define A 30
# define S 31
# define D 32

typedef struct	s_main t_main;

void			print_error_and_message(char *error_message);

/*------------------------------------ DEBUG ---------------------------------*/

void	print_grid(t_main *main);

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
	t_myimage	image;
}				t_main;

#endif