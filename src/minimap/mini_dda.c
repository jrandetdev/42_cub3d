/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:19:16 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/12 17:25:31 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_outside_minimap(t_main *main, float x, float y)
{
	int	xm;
	int	ym;
	int	size;
	int	map_width;
	int	map_height;

	size = main->minimap.tile_size;
	map_width = (int)trunc(main->map_struct.width);
	map_height = (int)trunc(main->map_struct.height);
	xm = (x - main->minimap.start_px) / size;
	ym = (y - main->minimap.start_py) / size;
	if (xm < 0 || ym < 0 || xm > map_width || ym > map_height)
		return (false);
	if (main->map_struct.map[ym][xm] == '1' ||
		main->map_struct.map[ym][xm] == '2')
		return (false);
	return (true);
}

static bool	check_outside_and_corner(t_main *main, float x, float y)
{
	if (!check_outside_minimap(main, x, y))
		return (false);
	if (!check_outside_minimap(main, x + 1, y))
		return (false);
	if (!check_outside_minimap(main, x - 1, y))
		return (false);
	return (true);
}

static t_vec2	dda_case_1(t_main *main, t_mini_dda_struct *mini_dda_struct)
{
	int		count_steps;
	int		step_in_x;
	float	x;
	float	y;
	t_vec2	vector;

	step_in_x = 1;
	x = mini_dda_struct->x_1;
	y = mini_dda_struct->y_1;
	count_steps = fabs(mini_dda_struct->delta_x);
	if (mini_dda_struct->delta_x < 0)
		step_in_x = -1;
	while (count_steps >= 0)
	{
		if (!check_outside_and_corner(main, x, y))
			break ;
		put_pixel_to_image(main, x, y, 0xF4E700);
		x += step_in_x;
		y += (mini_dda_struct->delta_y / mini_dda_struct->delta_x) * step_in_x;
		count_steps--;
	}
	vector.x = x;
	vector.y = y;
	return (vector);
}

static t_vec2	dda_case_2(t_main *main, t_mini_dda_struct *mini_dda_struct)
{
	int		count_steps;
	int		step_in_y;
	float	x;
	float	y;
	t_vec2	vector;

	step_in_y = 1;
	x = mini_dda_struct->x_1;
	y = mini_dda_struct->y_1;
	if (mini_dda_struct->delta_y < 0)
		step_in_y = -1;
	count_steps = fabs(mini_dda_struct->delta_y);
	while (count_steps >= 0)
	{
		if (!check_outside_and_corner(main, x, y))
			break ;
		put_pixel_to_image(main, x, y, 0xF4E700);
		y += step_in_y;
		x += (mini_dda_struct->delta_x / mini_dda_struct->delta_y) * step_in_y;
		count_steps--;
	}
	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vec2	mini_dda(t_main *main, float dst_x, float dst_y)
{
	int					size;
	t_mini_dda_struct	*mini_dda_struct;
	t_vec2				vector;

	mini_dda_struct = &main->mini_dda_struct;
	size = main->minimap.tile_size;
	mini_dda_struct->x_1 = main->minimap.start_px + main->player.x * size;
	mini_dda_struct->y_1 = main->minimap.start_py + main->player.y * size;
	mini_dda_struct->x_2 = main->minimap.start_px + dst_x * size;
	mini_dda_struct->y_2 = main->minimap.start_py + dst_y * size;
	mini_dda_struct->delta_x = mini_dda_struct->x_2 - mini_dda_struct->x_1;
	mini_dda_struct->delta_y = mini_dda_struct->y_2 - mini_dda_struct->y_1;
	if (fabs(mini_dda_struct->delta_y) <= fabs(mini_dda_struct->delta_x))
		vector = dda_case_1(main, mini_dda_struct);
	else
		vector = dda_case_2(main, mini_dda_struct);
	return (vector);
}
