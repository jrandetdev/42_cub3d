/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:47 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/22 15:49:57 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	apply_selection(t_main *main, int *menu, int selection)
{
	main->keys.enter = 0;
	if (selection == 0)
		*(menu) = RESOLUTION_OPTION;
	else if (selection == 1)
		*(menu) = FOV_OPTION;
	else if (selection == 3)
	{
		*(menu) = MAIN_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
}

void	show_option_menu(t_main *main, int *menu)
{
	int			i;
	int			selection;
	static int	menu_title = 0;

	i = 0;
	selection = 0;
	if (menu_title < 0)
		menu_title = 3;
	selection = menu_title % 4;
	print_menu_title(main, "OPTION");
	print_menu_section(main, selection, i++, "RESOLUTION");
	print_menu_section(main, selection, i++, "FOV");
	print_menu_section(main, selection, i++, "MINIMAP");
	print_menu_section(main, selection, i, "RETURN");
	if (main->keys.enter)
		apply_selection(main, menu, selection);
	else if (main->keys.up)
		menu_up(main, &menu_title);
	else if (main->keys.down)
		menu_down(main, &menu_title);
}
