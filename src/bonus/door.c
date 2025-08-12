/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/12 16:36:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	opening_door(t_main *main, int x, int y)
{
	main->map_struct.map[y][x] = DA;
	main->door.opening_pourcent = 0;
	main->door.state = OPENING;
	main->door.pos_x = x;
	main->door.pos_y = y;
}

static void	closing_door(t_main *main, char **map, int x, int y)
{
	if (map[(int)trunc(main->player.y)]
		[(int)trunc(main->player.x)] == map[y][x])
		return ;
	main->map_struct.map[y][x] = DA;
	main->door.opening_pourcent = 1;
	main->door.state = CLOSING;
	main->door.pos_x = x;
	main->door.pos_y = y;
}

void	playing_door_animation(t_main *main)
{
	if (main->door.state == OPENING)
	{
		if (main->door.opening_pourcent < 1)
		{
			main->door.opening_pourcent += DOOR_ANIMATION_SPEED;
			return ;
		}
		main->map_struct.map[main->door.pos_y][main->door.pos_x] = DO;
	}
	else if (main->door.state == CLOSING)
	{
		if (main->door.opening_pourcent > 0)
		{
			main->door.opening_pourcent -= DOOR_ANIMATION_SPEED;
			return ;
		}
		main->map_struct.map[main->door.pos_y][main->door.pos_x] = DC;
	}
	main->door.state = NONE;
}

bool	is_in_door_half(t_main *main, t_dda_struct *dda)
{
	float		width_pourcentage;
	float		width_pos_x;

	if (dda->side == 0)
		width_pos_x = main->player.y + dda->ray_diry * dda->perpwalldist;
	else
		width_pos_x = main->player.x + dda->ray_dirx * dda->perpwalldist;
	width_pourcentage = width_pos_x - floor(width_pos_x);
	dda->door_hit_percentage = width_pourcentage;
	if (width_pourcentage > (0.5 + (main->door.opening_pourcent / 2)))
		return (true);
	else if (width_pourcentage <= (0.5 - (main->door.opening_pourcent / 2)))
		return (true);
	return (false);
}

void	change_door_state(t_main *main)
{
	int		x;
	int		y;
	char	**map;

	main->keys.e = 0;
	map = main->map_struct.map;
	x = (int)trunc(main->player.x + (main->player.dir_x * 1.0));
	y = (int)trunc(main->player.y + (main->player.dir_y * 1.0));
	if (main->map_struct.map[y][x] == DC)
	{
		opening_door(main, x, y);
	}
	else if (main->map_struct.map[y][x] == DO)
	{
		closing_door(main, map, x, y);
	}
}
