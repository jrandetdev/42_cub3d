
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
	int			selected;
	static int	selection = 0;

	selected = 0;
	if (selection < 0)
		selection = 3;
	selected = selection % 4;
	mlx_string_put(main->mlx_ptr, main->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2 + 13, 0xFFFFFF, "PLAY");
	mlx_string_put(main->mlx_ptr, main->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2 + 26, 0xFFFFFF, "OPTION");
	mlx_string_put(main->mlx_ptr, main->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2 + 39, 0xFFFFFF, "DEBUG");
	mlx_string_put(main->mlx_ptr, main->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2 + 52, 0xFFFFFF, "QUIT");
	if (selected == 0)
		mlx_string_put(main->mlx_ptr, main->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2 + 13, 0xFFFB00, "PLAY");
	if (selected == 1)
		mlx_string_put(main->mlx_ptr, main->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2 + 26, 0xFFFB00, "OPTION");
	if (selected == 2)
		mlx_string_put(main->mlx_ptr, main->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2 + 39, 0xFFFB00, "DEBUG");
	if (selected == 3)
		mlx_string_put(main->mlx_ptr, main->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2 + 52, 0xFFFB00, "QUIT");
	if (main->keys.enter)
		apply_selection(main, main_menu, selected);
	else if (main->keys.up)
	{
		selection--;
		main->keys.up = 0;
	}
	else if (main->keys.down)
	{
		selection++;
		main->keys.down = 0;
	}
	printf("%d\n", selection);
}
