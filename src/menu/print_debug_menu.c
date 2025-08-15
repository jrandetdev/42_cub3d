/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:25:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 17:59:11 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	option_selected(t_main *main, int *menu, int option_selected,\
	int *menu_section);

void	show_debug_menu(t_main *main, int *menu)
{
	t_menu_display	param;
	static int		menu_title = 0;
	t_menu_options	*menu_option;

	menu_option = &main->menu.option;
	ft_bzero(&param, sizeof(t_menu_display));
	param.size = 3;
	if (menu_title < 0)
		menu_title = 3;
	param.y = WIN_HEIGHT / 2 - (param.size + 1 * 48);
	param.option_selected = menu_title % 4;
	print_menu_title(main, "DEBUG");
	print_box(main, &param, menu_option->show_minimap_grid, "MINIMAP GRID");
	print_box(main, &param, menu_option->fov, "MINIMAP FOV");
	print_menu_section(main, &param, "RETURN");
	if (main->interaction.keys.enter)
		option_selected(main, menu, param.option_selected, &menu_title);
	else if (main->interaction.keys.up || main->interaction.keys.down)
		menu_up_and_down(main, &menu_title);
}

static void	option_selected(t_main *main, int *menu, int option_selected,\
	int *menu_section)
{
	t_menu_options	*menu_option;

	menu_option = &main->menu.option;
	main->interaction.keys.enter = 0;
	if (option_selected == 0)
		menu_option->show_minimap_grid = !menu_option->show_minimap_grid;
	else if (option_selected == 1)
		menu_option->fov = !menu_option->fov;
	else if (option_selected == 2)
	{
		*(menu_section) = 0;
		if (!main->game_start)
			*(menu) = MAIN_MENU;
		else
			*menu = PAUSE_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
}
