/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:47 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 16:12:59 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	option_selected(t_main *main, int *menu, int option_selected, int *menu_title)
{
	main->interaction.keys.enter = 0;
	if (option_selected == 0)
	{
		*(menu) = MOUSE_SENSITIVITY_OPTION;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
	else if (option_selected == 1)
		main->menu.option.show_fps = !main->menu.option.show_fps;
	else if (option_selected == 2)
		main->menu.option.show_minimap = !main->menu.option.show_minimap;
	else if (option_selected == 3)
	{
		*(menu_title) = 0;
		if (!main->game_start)
			*(menu) = MAIN_MENU;
		else
			*menu = PAUSE_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
}

void	show_option_menu(t_main *main, int *menu)
{
	t_menu_display	param;
	static int		menu_title = 0;

	ft_bzero(&param, (sizeof(t_menu_display)));
	param.size = 4;
	if (menu_title < 0)
		menu_title = 3;
	param.y = WIN_HEIGHT / 2 - (param.size + 1 * 48);
	param.option_selected = menu_title % 4;
	print_menu_title(main, "OPTION");
	print_menu_section(main, &param, "MOUSE SENSITIVITY");
	print_box(main, &param, main->menu.option.show_fps, "SHOW FPS");
	print_box(main, &param, main->menu.option.show_minimap, "SHOW MINIMAP");
	print_menu_section(main, &param, "RETURN");
	if (main->interaction.keys.enter)
		option_selected(main, menu, param.option_selected, &menu_title);
	else if (main->interaction.keys.up || main->interaction.keys.down)
		menu_up_and_down(main, &menu_title);
}
