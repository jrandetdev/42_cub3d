/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:07:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 23:11:59 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_casting_loop(t_main *main, t_dda *dda, int x);
static void	handle_surface_hit(t_main *main, t_dda *dda, int x);
static void	handle_door_state(t_main *main, t_dda *dda, int x);
static void	correct_fish_eye(t_dda *dda);

void	digital_differential_analyzer(t_main *main, t_dda *dda, int x)
{
	dda->x = main->player.x;
	dda->y = main->player.y;
	dda->hit = 0;
	set_dda_params(main, dda);
	ray_casting_loop(main, dda, x);
	correct_fish_eye(dda);
}

/**
 * @param sideDistX est un vecteur que l'on multiplie avec un scalaire !
 * @param sideDisty est un vecteur que l'on multiplie avec un scalaire !
 * @brief On augmente le vecteur SideDistX ou SideDistY selon l'angle du vecteur
 */
static void	ray_casting_loop(t_main *main, t_dda *dda, int x)
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
		if (main->map.array[dda->y][dda->x] != 0)
			handle_surface_hit(main, dda, x);
	}
}

static void	handle_surface_hit(t_main *main, t_dda *dda, int x)
{
	if (main->map.array[dda->y][dda->x] == '1')
	{
		dda->hit = 1;
	}
	else if (main->map.array[dda->y][dda->x] == DC
		|| main->map.array[dda->y][dda->x] == DO
		|| main->map.array[dda->y][dda->x] == DA)
	{
		handle_door_state(main, dda, x);
	}
}

static void	handle_door_state(t_main *main, t_dda *dda, int x)
{
	if (main->interaction.keys.e && x == WIN_WIDTH / 2
		&& (main->map.array[dda->y][dda->x] == DO
		|| main->map.array[dda->y][dda->x] == DC))
	{
		correct_fish_eye(dda);
		if (dda->correct_distance < 3)
			change_door_state(main, dda->x, dda->y);
	}
	if (main->map.array[dda->y][dda->x] == DA)
	{
		correct_fish_eye(dda);
		if (is_in_door_half(main, dda))
			dda->hit = 3;
	}
	if (main->map.array[dda->y][dda->x] == DC)
		dda->hit = 2;
}

static void	correct_fish_eye(t_dda *dda)
{
	if (dda->side == 0)
		dda->correct_distance = (dda->dist_to_x_int - dda->delta_x);
	else
		dda->correct_distance = (dda->dist_to_y_int - dda->delta_y);
}
