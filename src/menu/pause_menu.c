/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:55 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 16:12:19 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	option_selected(t_main *main, int *main_menu, int option_selected)
{
	main->interaction.keys.enter = 0;
	if (option_selected == 0)
		*(main_menu) = NO_MENU;
	if (option_selected == 1)
	{
		*(main_menu) = OPTION_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
	if (option_selected == 2)
	{
		*(main_menu) = DEBUG_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
	else if (option_selected == 3)
		exit_cub3d(main, 0);
}

void	show_pause_menu(t_main *main, int *main_menu)
{
	t_menu_display	param;
	static int		menu_title = 0;

	ft_bzero(&param, (sizeof(t_menu_display)));
	param.size = 4;
	if (menu_title < 0)
		menu_title = 3;
	param.y = WIN_HEIGHT / 2 - (param.size + 1 * 48);
	param.option_selected = menu_title % 4;
	print_menu_title(main, GAME_NAME);
	print_menu_section(main, &param, "RESUME");
	print_menu_section(main, &param, "OPTION");
	print_menu_section(main, &param, "DEBUG");
	print_menu_section(main, &param, "QUIT");
	if (main->interaction.keys.enter)
		option_selected(main, main_menu, param.option_selected);
	else if (main->interaction.keys.up || main->interaction.keys.down)
		menu_up_and_down(main, &menu_title);
	mlx_string_put(main->mlx_ptr, main->mlx_win, 10, WIN_HEIGHT - 20, 0xFFFFFF,
		"by : jrandet and hdougoud");
}
