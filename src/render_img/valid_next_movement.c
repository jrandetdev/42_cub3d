/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_next_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:03:07 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/23 12:02:26 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_corner(t_main *main, double next_x, double next_y)
{
	char	**map;

	map = main->map_struct.map;
	if (map[(int)trunc(next_y - 0.1)][(int)trunc(next_x)] == '1'
			&& map[(int)trunc(next_y)][(int)trunc(next_x + 0.1)] == '1')
		return (false);
	if (map[(int)trunc(next_y + 0.1)][(int)trunc(next_x)] == '1'
			&& map[(int)trunc(next_y)][(int)trunc(next_x - 0.1)] == '1')
		return (false);
	if (map[(int)trunc(next_y + 0.1)][(int)trunc(next_x)] == '1'
			&& map[(int)trunc(next_y)][(int)trunc(next_x + 0.1)] == '1')
		return (false);
	if (map[(int)trunc(next_y - 0.1)][(int)trunc(next_x)] == '1'
			&& map[(int)trunc(next_y)][(int)trunc(next_x - 0.1)] == '1')
		return (false);
	return (true);
}

void	valid_next_movement_up(t_main *main, double next_x, double next_y)
{
	double	valid_x;
	double	valid_y;

	valid_x = next_x + main->player.dir_x * 0.3;
	valid_y = next_y + main->player.dir_y * 0.3;
	if (main->map_struct.map[(int)trunc(valid_y)][(int)trunc(valid_x)] == '0')
	{
		if (check_corner(main, next_x, next_y))
		{
			main->player.x = next_x;
			main->player.y = next_y;
		}
	}
}

void	valid_next_movement_down(t_main *main, double next_x, double next_y)
{
	double	valid_x;
	double	valid_y;

	valid_x = next_x - main->player.dir_x * 0.3;
	valid_y = next_y - main->player.dir_y * 0.3;
	if (main->map_struct.map[(int)trunc(valid_y)][(int)trunc(valid_x)] == '0')
	{
		if (check_corner(main, next_x, next_y))
		{
			main->player.x = next_x;
			main->player.y = next_y;
		} 
	}
}

void	valid_next_movement_right(t_main *main, double next_x, double next_y)
{
	double	valid_x;
	double	valid_y;

	valid_x = next_x + main->player.plane_x * 0.3;
	valid_y = next_y + main->player.plane_y * 0.3;
	if (main->map_struct.map[(int)trunc(valid_y)][(int)trunc(valid_x)] == '0')
	{
		if (check_corner(main, next_x, next_y))
		{
			main->player.x = next_x;
			main->player.y = next_y;
		}
	}
}

void	valid_next_movement_left(t_main *main, double next_x, double next_y)
{
	double	valid_x;
	double	valid_y;

	valid_x = next_x - main->player.plane_x * 0.3;
	valid_y = next_y - main->player.plane_y * 0.3;
	if (main->map_struct.map[(int)trunc(valid_y)][(int)trunc(valid_x)] == '0')
	{
		if (check_corner(main, next_x, next_y))
		{
			main->player.x = next_x;
			main->player.y = next_y;
		}
	}
}
