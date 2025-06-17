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

typedef struct	s_main t_main;

void			print_error_and_message(char *error_message);

typedef struct	s_main
{
	char	**map;
}				t_main;

#endif