/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:11:00 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:33:39 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_main *main)
{
	char	*door_file;

	// main->menu.current_menu = 1;
	// main->menu.option.fov = 1;
	// main->menu.option.show_minimap = 1;
	main->interaction.mouse.sensitivity = 25;
	main->interaction.mouse.x = WIN_WIDTH / 2;
	if (gettimeofday(&main->bonus.last_sec, NULL))
		print_error_syscall(main, "GetTimeOfDay failed in init_cub3d");
	door_file = "./assets/textures/cool_door.xpm";
	load_personal_texture(main, &main->assets.texture_bank.door, door_file);
}
