
#include "cub3d.h"

static void	apply_selection(t_main *main, int *menu, int selection)
{
	main->keys.enter = 0;
	if (selection == 0)
		main->param.show_minimap_grid = !main->param.show_minimap_grid;
	else if (selection == 1)
		main->param.fov = !main->param.fov;
	else if (selection == 2)
	{
		if (!main->game_start)
			*(menu) = MAIN_MENU;
		else
			*menu = PAUSE_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
}

void	show_debug_menu(t_main *main, int *menu)
{
	t_menu_struct	param;
	static int		menu_title = 0;

	ft_bzero(&param, sizeof(t_menu_struct));
	param.menu_size = 3;
	if (menu_title < 0)
		menu_title = 3;
	param.y = main->cal.half_wh - (param.menu_size * 48);
	param.selection = menu_title % 4;
	print_menu_title(main, "DEBUG");
	print_case(main, &param, main->param.show_minimap_grid, "GRID");
	print_case(main, &param, main->param.fov, "FOV");
	print_menu_section(main, &param, "RETURN");
	if (main->keys.enter)
	{
		menu_title = 0;
		apply_selection(main, menu, param.selection);
	}
	else if (main->keys.up)
		menu_up(main, &menu_title);
	else if (main->keys.down)
		menu_down(main, &menu_title);
}