/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:25:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 17:20:09 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	selection(t_main *main, int *menu, int selection, int *menu_section)
{
	main->interaction.keys.enter = 0;
	if (selection == 0)
		main->menu.display.current_menu.option.show_minimap_grid = !main->menu.display.current_menu.option.show_minimap_grid;
	else if (selection == 1)
		main->menu.display.current_menu.option.fov = !main->menu.display.current_menu.option.fov;
	else if (selection == 2)
	{
		*(menu_section) = 0;
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
	param.y = WIN_HEIGHT / 2 - (param.menu_size + 1 * 48);
	param.selection = menu_title % 4;
	print_menu_title(main, "DEBUG");
	print_box(main, &param, main->menu.display.current_menu.option.show_minimap_grid, "MINIMAP GRID");
	print_box(main, &param, main->menu.display.current_menu.option.fov, "MINIMAP FOV");
	print_menu_section(main, &param, "RETURN");
	if (main->interaction.keys.enter)
		selection(main, menu, param.selection, &menu_title);
	else if (main->interaction.keys.up || main->interaction.keys.down)
		menu_up_and_down(main, &menu_title);
}
