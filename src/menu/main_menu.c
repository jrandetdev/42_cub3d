
#include "cub3d.h"

static void	apply_selection(t_main *main, int *main_menu, int selection)
{
	if (selection == 0)
		*(main_menu) = 0;
	else if (selection == 3)
		exit_cub3d(main, NULL);
}

void	show_main_menu(t_main *main, int *main_menu)
{
	int			i;
	int			selection;
	static int	menu_title = 0;

	i = 0;
	selection = 0;
	if (menu_title < 0)
		menu_title = 3;
	selection = menu_title % 4;
	print_menu_title(main, selection, i++, "PLAY");
	print_menu_title(main, selection, i++, "OPTION");
	print_menu_title(main, selection, i++, "DEBUG");
	print_menu_title(main, selection, i, "QUIT");
	if (main->keys.enter)
		apply_selection(main, main_menu, selection);
	else if (main->keys.up)
	{
		menu_title--;
		main->keys.up = 0;
	}
	else if (main->keys.down)
	{
		menu_title++;
		main->keys.down = 0;
	}
}
