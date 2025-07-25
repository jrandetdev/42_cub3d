/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:55 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/22 15:39:22 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	apply_selection(t_main *main, int *main_menu, int selection)
{
	main->keys.enter = 0;
	if (selection == 0)
		*(main_menu) = NO_MENU;
	if (selection == 1)
	{
		*(main_menu) = OPTION_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
	if (selection == 2)
	{
		*(main_menu) = DEBUG_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
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
	print_menu_title(main, GAME_NAME);
	print_menu_section_4(main, selection, i++, "PLAY");
	print_menu_section_4(main, selection, i++, "OPTION");
	print_menu_section_4(main, selection, i++, "DEBUG");
	print_menu_section_4(main, selection, i, "QUIT");
	if (main->keys.enter)
		apply_selection(main, main_menu, selection);
	else if (main->keys.up)
		menu_up(main, &menu_title);
	else if (main->keys.down)
		menu_down(main, &menu_title);
	mlx_string_put(main->mlx_ptr, main->mlx_win, 10, WIN_HEIGHT - 20, 0xFFFFFF,
		"by : jrandet and hdougoud");
}
