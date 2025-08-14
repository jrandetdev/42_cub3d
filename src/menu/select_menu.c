/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:42 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/14 14:55:10 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_menu(t_main *main, int *menu)
{
	if (*menu == MAIN_MENU)
		display_main_menu(main, menu);
	else if (*menu == PAUSE_MENU)
		display_pause_menu(main, menu);
	else if (*menu == OPTION_MENU)
		display_option_menu(main, menu);
	else if (*menu == DEBUG_MENU)
		display_debug_menu(main, menu);
	else if (*menu == MOUSE_SENSITIVITY_OPTION)
		display_mouse_sensitivity_menu(main, menu);
}
