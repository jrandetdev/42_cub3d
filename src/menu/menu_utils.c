
#include "cub3d.h"

char ft_capitalize(char letter)
{
	if (letter >= 'A' || letter <= 'Z')
		return (letter);
	return (letter ^ 32);
}

void	menu_up(t_main *main, int *selection)
{
	*(selection) -= 1;
	main->keys.up = 0;
}

void menu_down(t_main *main, int *selection)
{
	*(selection) += 1;
	main->keys.down = 0;
}