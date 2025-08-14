/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:06:09 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 18:59:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_up_and_down(t_main *main);
static void	player_right_and_left(t_main *main);
static void	player_rotation(t_main *main);
static void	apply_player_rotation(t_main *main, float rotation_speed);

void	player_movement(t_main *main)
{
	player_up_and_down(main);
	player_right_and_left(main);
	player_rotation(main);
}

static void	player_up_and_down(t_main *main)
{
	float	new_x;
	float	new_y;
	float	player_speed;

	player_speed = PLAYER_SPEED;
	if (main->interaction.keys.shift)
		player_speed += 0.08;
	if (main->interaction.keys.w == 1)
	{
		new_x = main->player.x + (main->player.dir_x * player_speed);
		new_y = main->player.y + (main->player.dir_y * player_speed);
		valid_next_movement_up(main, new_x, new_y);
	}
	if (main->interaction.keys.s == 1)
	{
		new_x = main->player.x - (main->player.dir_x * PLAYER_SPEED);
		new_y = main->player.y - (main->player.dir_y * PLAYER_SPEED);
		valid_next_movement_down(main, new_x, new_y);
	}
}

static void	player_right_and_left(t_main *main)
{
	float	new_x;
	float	new_y;

	if (main->interaction.keys.d == 1)
	{
		new_x = main->player.x + (main->player.plane_x * PLAYER_SPEED);
		new_y = main->player.y + (main->player.plane_y * PLAYER_SPEED);
		valid_next_movement_right(main, new_x, new_y);
	}
	if (main->interaction.keys.a == 1)
	{
		new_x = main->player.x - (main->player.plane_x * PLAYER_SPEED);
		new_y = main->player.y - (main->player.plane_y * PLAYER_SPEED);
		valid_next_movement_left(main, new_x, new_y);
	}
}

static void	player_rotation(t_main *main)
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


