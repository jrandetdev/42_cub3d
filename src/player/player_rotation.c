/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:38:43 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 12:24:35 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	apply_player_rotation(t_main *main, float rotation_speed);

void	player_rotation(t_main *main)
{
	float	rotation_speed;

	rotation_speed = 0;
	if (main->interaction.keys.left || main->interaction.keys.right)
	{
		if (main->interaction.keys.left)
			rotation_speed = -ROTATION_SPEED;
		if (main->interaction.keys.right)
			rotation_speed = ROTATION_SPEED;
		if (main->interaction.keys.left && main->interaction.keys.right)
			return ;
	}
	else if (main->interaction.mouse.dist)
	{
		if (main->interaction.mouse.dist > 0)
			rotation_speed = main->interaction.mouse.dist * ROTATION_SPEED;
		else if (main->interaction.mouse.dist < 0)
			rotation_speed = main->interaction.mouse.dist * ROTATION_SPEED;
	}
	apply_player_rotation(main, rotation_speed);
	if (main->interaction.mouse.dist)
		main->interaction.mouse.dist = 0;
}

static void	apply_player_rotation(t_main *main, float rotation_speed)
{
	float	old_plane_x;
	float	old_dir_x;

	old_dir_x = main->player.dir_x;
	printf("R dir x %f\n", main->player.dir_x);
	printf("R dir y %f\n", main->player.dir_y);
	main->player.dir_x = main->player.dir_x * cos(rotation_speed)
		- main->player.dir_y * sin(rotation_speed);
	main->player.dir_y = old_dir_x * sin(rotation_speed)
		+ main->player.dir_y * cos(rotation_speed);
	old_plane_x = main->player.plane_x;
	main->player.plane_x = main->player.plane_x * cos(rotation_speed)
		- main->player.plane_y * sin(rotation_speed);
	main->player.plane_y = old_plane_x * sin(rotation_speed)
		+ main->player.plane_y * cos(rotation_speed);
	main->player.angle = atan2(main->player.dir_y, main->player.dir_x);
}
