/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 20:25:03 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	opening_door(t_main *main, int x, int y);
static void	closing_door(t_main *main, char **map, int x, int y);

void	change_door_state(t_main *main, int x, int y)
{
	char	**map;

	main->interaction.keys.e = 0;
	map = main->map.array;
	if (main->map.array[y][x] == DC)
	{
		opening_door(main, x, y);
	}
	else if (main->map.array[y][x] == DO)
	{
		closing_door(main, map, x, y);
	}
}

static void	opening_door(t_main *main, int x, int y)
{
	if (main->assets.door.state)
		return ;
	main->map.array[y][x] = DA;
	main->assets.door.opening_pourcent = 0;
	main->assets.door.state = OPENING;
	main->assets.door.pos_x = x;
	main->assets.door.pos_y = y;
}

static void	closing_door(t_main *main, char **map, int x, int y)
{
	if (main->assets.door.state)
		return ;
	if (map[(int)trunc(main->player.y)]
		[(int)trunc(main->player.x)] == map[y][x])
		return ;
	main->map.array[y][x] = DA;
	main->assets.door.opening_pourcent = 1;
	main->assets.door.state = CLOSING;
	main->assets.door.pos_x = x;
	main->assets.door.pos_y = y;
}

void	playing_door_animation(t_main *main)
{
	if (main->assets.door.state == OPENING)
	{
		if (main->assets.door.opening_pourcent < 1)
		{
			main->assets.door.opening_pourcent += DOOR_ANIMATION_SPEED;
			return ;
		}
		main->map.array[main->assets.door.pos_y][main->assets.door.pos_x] = DO;
	}
	else if (main->assets.door.state == CLOSING)
	{
		if (main->assets.door.opening_pourcent > 0)
		{
			main->assets.door.opening_pourcent -= DOOR_ANIMATION_SPEED;
			return ;
		}
		main->map.array[main->assets.door.pos_y][main->assets.door.pos_x] = DC;
	}
	main->assets.door.state = NONE;
}

bool	is_in_door_half(t_main *main, t_dda *dda)
{
	float		width_pourcentage;
	float		width_pos_x;

	if (dda->side == 0)
		width_pos_x = main->player.y + dda->ray.y * dda->correct_distance;
	else
		width_pos_x = main->player.x + dda->ray.x * dda->correct_distance;
	width_pourcentage = width_pos_x - floor(width_pos_x);
	dda->door_hit_percentage = width_pourcentage;
	if (width_pourcentage > (0.5 + (main->assets.door.opening_pourcent / 2)))
		return (true);
	else if (width_pourcentage <= (0.5 - (main->assets.door.opening_pourcent / 2)))
		return (true);
	return (false);
}
