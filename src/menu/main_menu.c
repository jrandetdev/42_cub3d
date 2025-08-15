/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:55 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 16:11:35 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	option_selected(t_main *main, int *current_menu, int option_selected)
{
	main->interaction.keys.enter = 0;
	if (option_selected == 0)
	{
		main->game_start = 1;
		*(current_menu) = NO_MENU;
	}
	if (option_selected == 1)
	{
		*(current_menu) = OPTION_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
	if (option_selected == 2)
	{
		*(current_menu) = DEBUG_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
	else if (option_selected == 3)
		exit_cub3d(main, 0);
}

void	show_main_menu(t_main *main, int *current_menu)
{
	t_menu_display	menu_display;
	static int		menu_title = 0;

	ft_bzero(&menu_display, (sizeof(t_menu_display)));
	menu_display.size = 4;
	if (menu_title < 0)
		menu_title = 3;
	menu_display.y = WIN_HEIGHT / 2 - (menu_display.size + 1 * 48);
	menu_display.option_selected = menu_title % 4;
	print_menu_title(main, GAME_NAME);
	print_menu_section(main, &menu_display, "PLAY");
	print_menu_section(main, &menu_display, "OPTION");
	print_menu_section(main, &menu_display, "DEBUG");
	print_menu_section(main, &menu_display, "QUIT");
	if (main->interaction.keys.enter)
		option_selected(main, current_menu, menu_display.option_selected);
	else if (main->interaction.keys.up || main->interaction.keys.down)
		menu_up_and_down(main, &menu_title);
	mlx_string_put(main->mlx_ptr, main->mlx_win, 10, WIN_HEIGHT - 20, 0xFFFFFF,
		"by : jrandet and hdougoud");
}
