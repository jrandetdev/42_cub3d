/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_forward_and_backward.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:03:07 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 12:56:23 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_next_movement_up(t_main *main, float next_x, float next_y)
{
	float	current_x;
	float	current_y;
	float	valid_x;
	float	valid_y;

	current_x = main->player.x;
	current_y = main->player.y;
	valid_x = next_x + main->player.dir_x * PLAYER_SPEED;
	valid_y = next_y + main->player.dir_y * PLAYER_SPEED;
	printf("%c\n", main->map.array[(int)trunc(next_y)][(int)trunc(next_x)]);
	if (main->map.array[(int)trunc(current_y)]
		[(int)trunc(valid_x)] == '0'
		|| main->map.array[(int)trunc(current_y)]
		[(int)trunc(valid_x)] == '3')
		main->player.x = next_x;
	if (main->map.array[(int)trunc(valid_y)]
		[(int)trunc(current_x)] == '0'
		|| main->map.array[(int)trunc(valid_y)]
		[(int)trunc(current_x)] == '3')
		main->player.y = next_y;
}

void	valid_next_movement_down(t_main *main, float next_x, float next_y)
{
	float	current_x;
	float	current_y;
	float	valid_x;
	float	valid_y;

	current_x = main->player.x;
	current_y = main->player.y;
	valid_x = next_x - main->player.dir_x * PLAYER_SPEED;
	valid_y = next_y - main->player.dir_y * PLAYER_SPEED;
	if (main->map.array[(int)trunc(current_y)]
		[(int)trunc(valid_x)] == '0'
		|| main->map.array[(int)trunc(current_y)]
		[(int)trunc(valid_x)] == '3')
		main->player.x = next_x;
	if (main->map.array[(int)trunc(valid_y)]
		[(int)trunc(current_x)] == '0'
		|| main->map.array[(int)trunc(valid_y)]
		[(int)trunc(current_x)] == '3')
		main->player.y = next_y;
}




