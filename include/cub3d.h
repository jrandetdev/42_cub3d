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

# ifndef BUFFERSIZE
# define BUFFERSIZE 20
# endif

typedef struct	s_main t_main;

typedef struct	s_main
{
	char	**map;
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