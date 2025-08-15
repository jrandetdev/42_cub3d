/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:06:09 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 12:54:56 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_up_and_down(t_main *main);
static void	player_right_and_left(t_main *main);

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
		player_speed += PLAYER_SPEED;
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
