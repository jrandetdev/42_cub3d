/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:07:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 18:30:52 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_casting_loop(t_main *main, t_dda *dda);
static void	handle_surface_hit(t_main *main, t_dda *dda);
static void	handle_door_state(t_main *main, t_dda *dda);
static void	correct_fish_eye(t_dda *dda);

void	digital_differential_analyzer(t_main *main, t_dda *dda)
{
	dda->x = main->player.x;
	dda->y = main->player.y;
	dda->hit = 0;
	set_dda_params(main, dda);
	ray_casting_loop(main, dda);
	correct_fish_eye(dda);
}

/**
 * @param sideDistX est un vecteur que l'on multiplie avec un scalaire !
 * @param sideDisty est un vecteur que l'on multiplie avec un scalaire !
 * @brief On augmente le vecteur SideDistX ou SideDistY selon l'angle du vecteur
 */
// t_vector	vector;
// continue tant que mur n'est pas hit
static void	ray_casting_loop(t_main *main, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->dist_to_x_int < dda->dist_to_y_int)
		{
			dda->dist_to_x_int += dda->delta_x;
			dda->x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->dist_to_y_int += dda->delta_y;
			dda->y += dda->step_y;
			dda->side = 1;
		}
		if (main->map_struct.map[dda->y][dda->x] != 0)
			handle_surface_hit(main, dda);
	}
}

static void	handle_surface_hit(t_main *main, t_dda *dda)
{
	if (main->map_struct.map[dda->y][dda->x] == '1')
	{
		dda->hit = 1;
	}
	else if (main->map_struct.map[dda->y][dda->x] == DC ||
		main->map_struct.map[dda->y][dda->x] == DA)
	{
		handle_door_state(main, dda);
	}
}

static void	handle_door_state(t_main *main, t_dda *dda)
{
	if (main->map_struct.map[dda->y][dda->x] == DA)
	{
		correct_fish_eye(dda);
		if (is_in_door_half(main, dda))
			dda->hit = 3;
	}
	else
		dda->hit = 2;
}

static void	correct_fish_eye(t_dda *dda)
{
	if (dda->side == 0)
		dda->correct_distance = (dda->dist_to_x_int - dda->delta_x);
	else
		dda->correct_distance = (dda->dist_to_y_int - dda->delta_y);
}
