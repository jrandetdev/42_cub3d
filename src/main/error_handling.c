#include "cub3d.h"

void	print_error_and_message(char *error_message)
{
	printf("\033[0;31m");
	printf("Error\n");
	printf("\033[0m");
	ft_putendl_fd(error_message, 2);
}