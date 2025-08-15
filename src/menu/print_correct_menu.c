/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_correct_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:42 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 16:57:25 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_correct_menu(t_main *main, int *menu)
{
	mlx_mouse_show(main->mlx_ptr, main->mlx_win);
	if (*menu == MAIN_MENU)
		show_main_menu(main, menu);
	else if (*menu == PAUSE_MENU)
		show_pause_menu(main, menu);
	else if (*menu == OPTION_MENU)
		show_option_menu(main, menu);
	else if (*menu == DEBUG_MENU)
		show_debug_menu(main, menu);
	else if (*menu == MOUSE_SENSITIVITY_OPTION)
		show_mouse_sensitivity_menu(main, menu);
}
