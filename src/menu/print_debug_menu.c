
#include "cub3d.h"

static void	apply_selection(t_main *main, int *menu, int selection)
{
	main->keys.enter = 0;
	if (selection == 0)
		*(menu) = RESOLUTION_OPTION;
	else if (selection == 1)
		*(menu) = FOV_OPTION;
	else if (selection == 2)
	{
		*(menu) = MAIN_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
}

void	show_debug_menu(t_main *main, int *menu)
{
	int			i;
	int			selection;
	static int	menu_title = 0;

	i = 0;
	selection = 0;
	if (menu_title < 0)
		menu_title = 3;
	selection = menu_title % 4;
	print_menu_title(main, "DEBUG");
	print_menu_section_3(main, selection, i++, "GRID");
	print_menu_section_3(main, selection, i++, "FOV");
	print_menu_section_3(main, selection, i, "RETURN");
	if (main->keys.enter)
	{
		menu_title = 0;
		apply_selection(main, menu, selection);
	}
	else if (main->keys.up)
		menu_up(main, &menu_title);
	else if (main->keys.down)
		menu_down(main, &menu_title);
}