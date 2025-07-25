/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_next_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:03:07 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/25 12:15:43 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static bool	check_corner(t_main *main, double next_x, double next_y)
// {
// 	char	**map;

// 	map = main->map_struct.map;
// 	if (map[(int)trunc(next_y - 0.1)][(int)trunc(next_x)] == '1'
// 			&& map[(int)trunc(next_y)][(int)trunc(next_x + 0.1)] == '1')
// 		return (false);
// 	if (map[(int)trunc(next_y + 0.1)][(int)trunc(next_x)] == '1'
// 			&& map[(int)trunc(next_y)][(int)trunc(next_x - 0.1)] == '1')
// 		return (false);
// 	if (map[(int)trunc(next_y + 0.1)][(int)trunc(next_x)] == '1'
// 			&& map[(int)trunc(next_y)][(int)trunc(next_x + 0.1)] == '1')
// 		return (false);
// 	if (map[(int)trunc(next_y - 0.1)][(int)trunc(next_x)] == '1'
// 			&& map[(int)trunc(next_y)][(int)trunc(next_x - 0.1)] == '1')
// 		return (false);
// 	return (true);
// }

void	valid_next_movement_up(t_main *main, double next_x, double next_y)
{
	double	current_x;
	double	current_y;
	double	valid_x;
	double	valid_y;

	current_x = main->player.x;
	current_y = main->player.y;
	valid_x = next_x + main->player.dir_x * 0.08;
	valid_y = next_y + main->player.dir_y * 0.08;
	if (main->map_struct.map[(int)trunc(current_y)][(int)trunc(valid_x)] == '0'
		|| main->map_struct.map[(int)trunc(current_y)][(int)trunc(valid_x)] == '3')
		main->player.x = next_x;
	if (main->map_struct.map[(int)trunc(valid_y)][(int)trunc(current_x)] == '0'
		|| main->map_struct.map[(int)trunc(valid_y)][(int)trunc(current_x)] == '3')
		main->player.y = next_y;
}

void	valid_next_movement_down(t_main *main, double next_x, double next_y)
{
	double	current_x;
	double	current_y;
	double	valid_x;
	double	valid_y;

	current_x = main->player.x;
	current_y = main->player.y;
	valid_x = next_x - main->player.dir_x * 0.08;
	valid_y = next_y - main->player.dir_y * 0.08;
	if (main->map_struct.map[(int)trunc(current_y)][(int)trunc(valid_x)] == '0'
		|| main->map_struct.map[(int)trunc(current_y)][(int)trunc(valid_x)] == '3')
		main->player.x = next_x;
	if (main->map_struct.map[(int)trunc(valid_y)][(int)trunc(current_x)] == '0'
		|| main->map_struct.map[(int)trunc(valid_y)][(int)trunc(current_x)] == '3')
		main->player.y = next_y;
}

void	valid_next_movement_right(t_main *main, double next_x, double next_y)
{
	double	current_x;
	double	current_y;
	double	valid_x;
	double	valid_y;

	current_x = main->player.x;
	current_y = main->player.y;
	valid_x = next_x + main->player.plane_x * 0.08;
	valid_y = next_y + main->player.plane_y * 0.08;
	if (main->map_struct.map[(int)trunc(current_y)][(int)trunc(valid_x)] == '0'
		|| main->map_struct.map[(int)trunc(current_y)][(int)trunc(valid_x)] == '3')
		main->player.x = next_x;
	if (main->map_struct.map[(int)trunc(valid_y)][(int)trunc(current_x)] == '0'
		|| main->map_struct.map[(int)trunc(valid_y)][(int)trunc(current_x)] == '3')
		main->player.y = next_y;
}

void	valid_next_movement_left(t_main *main, double next_x, double next_y)
{
	double	current_x;
	double	current_y;
	double	valid_x;
	double	valid_y;

	current_x = main->player.x;
	current_y = main->player.y;
	valid_x = next_x - main->player.plane_x * 0.08;
	valid_y = next_y - main->player.plane_y * 0.08;
	if (main->map_struct.map[(int)trunc(current_y)][(int)trunc(valid_x)] == '0'
		|| main->map_struct.map[(int)trunc(current_y)][(int)trunc(valid_x)] == '3')
		main->player.x = next_x;
	if (main->map_struct.map[(int)trunc(valid_y)][(int)trunc(current_x)] == '0'
		|| main->map_struct.map[(int)trunc(valid_y)][(int)trunc(current_x)] == '3')
		main->player.y = next_y;
}