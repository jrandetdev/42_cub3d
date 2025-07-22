/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_correct_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:42 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/22 15:50:02 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_correct_menu(t_main *main, int *menu)
{
	if (*menu == MAIN_MENU)
		show_main_menu(main, menu);
	else if (*menu == OPTION_MENU)
		show_option_menu(main, menu);
}
