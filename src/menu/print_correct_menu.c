
#include "cub3d.h"

void	print_correct_menu(t_main *main, int *menu)
{
	if (*menu == MAIN_MENU)
		show_main_menu(main, menu);
	else if (*menu == OPTION_MENU)
		show_option_menu(main, menu);
}