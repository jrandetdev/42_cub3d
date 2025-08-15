/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu_sections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:11:43 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 14:19:21 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_menu_sections(t_main *main, t_menu_display *menu)
{
	print_menu_title(main, GAME_NAME);
	print_menu_section(main, menu, "PLAY");
	print_menu_section(main, menu, "OPTION");
	print_menu_section(main, menu, "DEBUG");
	print_menu_section(main, menu, "QUIT");
}
