/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:07:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/08 11:31:44 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_perpwall_dist(t_dda_struct *dda)
{
	if (dda->side == 0)
		dda->perpwalldist = (dda->sideDistX - dda->delta_x);
	else
		dda->perpwalldist = (dda->sideDistY - dda->delta_y);
}

static void	handle_door_state(t_main *main, t_dda_struct *dda)
{
	if (main->map_struct.map[dda->mapY][dda->mapX] == DA)
	{
		get_perpwall_dist(dda);
		if (is_in_door_half(main, dda))
			dda->hit = 3;
	}
	else
		dda->hit = 2;
}

/**
 * @param sideDistX est un vecteur que l'on multiplie avec un scalaire !
 * @param sideDisty est un vecteur que l'on multiplie avec un scalaire !
 * @brief On augmente le vecteur SideDistX ou SideDistY selon l'angle du vecteur
 */
// t_vec2	vector;
// continue tant que mur n'est pas hit
static void	dda_main_loop(t_main *main, t_dda_struct *dda)
{
	while (dda->hit == 0)
	{
		if (dda->sideDistX < dda->sideDistY)
		{
			dda->sideDistX += dda->delta_x;
			dda->mapX += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->sideDistY += dda->delta_y;
			dda->mapY += dda->step_y;
			dda->side = 1;
		}
		if (main->map_struct.map[dda->mapY][dda->mapX] == '1')
		{
			dda->hit = 1;
		}
		else if (main->map_struct.map[dda->mapY][dda->mapX] == DC ||
			main->map_struct.map[dda->mapY][dda->mapX] == DA)
		{
			handle_door_state(main, dda);
		}
	}
}

// si le rayon est dans la partie gauche de l'ecrann, step x sera -1
static void	get_step_and_sidedist(t_main *main, t_dda_struct *dda)
{
	if (dda->ray_dirx < 0)
	{
		dda->step_x = -1;
		dda->sideDistX = (main->player.x - dda->mapX) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->sideDistX = (dda->mapX + 1.0 - main->player.x) * dda->delta_x;
	}
	if (dda->ray_diry < 0)
	{
		dda->step_y = -1;
		dda->sideDistY = (main->player.y - dda->mapY) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->sideDistY = (dda->mapY + 1.0 - main->player.y) * dda->delta_y;
	}
}

void	digital_differential_analyzer(t_main *main, t_dda_struct *dda_struct)
{
	dda_struct->mapX = main->player.x;
	dda_struct->mapY = main->player.y;
	if (dda_struct->ray_dirx == 0)
		dda_struct->delta_x = pow(10, 30);
	else
		dda_struct->delta_x = fabs(1 / dda_struct->ray_dirx);
	if (dda_struct->ray_diry == 0)
		dda_struct->delta_y = pow(10, 30);
	else
		dda_struct->delta_y = fabs(1 / dda_struct->ray_diry);
	dda_struct->hit = 0;
	get_step_and_sidedist(main, dda_struct);
	dda_main_loop(main, dda_struct);
	get_perpwall_dist(dda_struct);
}
