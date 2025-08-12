/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:07:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/12 18:14:43 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_perpwall_dist(t_dda *dda)
{
	if (dda->side == 0)
		dda->perpwalldist = (dda->sidedistx - dda->delta_x);
	else
		dda->perpwalldist = (dda->sidedisty - dda->delta_y);
}

static void	handle_door_state(t_main *main, t_dda *dda)
{
	if (main->map_struct.map[dda->mapy][dda->mapx] == DA)
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
static void	dda_main_loop(t_main *main, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->sidedistx < dda->sidedisty)
		{
			dda->sidedistx += dda->delta_x;
			dda->mapx += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->sidedisty += dda->delta_y;
			dda->mapy += dda->step_y;
			dda->side = 1;
		}
		if (main->map_struct.map[dda->mapy][dda->mapx] == '1')
		{
			dda->hit = 1;
		}
		else if (main->map_struct.map[dda->mapy][dda->mapx] == DC ||
			main->map_struct.map[dda->mapy][dda->mapx] == DA)
		{
			handle_door_state(main, dda);
		}
	}
}

// si le rayon est dans la partie gauche de l'ecrann, step x sera -1
static void	get_step_and_sidedist(t_main *main, t_dda *dda)
{
	if (dda->ray_dirx < 0)
	{
		dda->step_x = -1;
		dda->sidedistx = (main->player.x - dda->mapx) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->sidedistx = (dda->mapx + 1.0 - main->player.x) * dda->delta_x;
	}
	if (dda->ray_diry < 0)
	{
		dda->step_y = -1;
		dda->sidedisty = (main->player.y - dda->mapy) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->sidedisty = (dda->mapy + 1.0 - main->player.y) * dda->delta_y;
	}
}

void	digital_differential_analyzer(t_main *main, t_dda *dda)
{
	dda->mapx = main->player.x;
	dda->mapy = main->player.y;
	if (dda->ray_dirx == 0)
		dda->delta_x = pow(10, 30);
	else
		dda->delta_x = fabs(1 / dda->ray_dirx);
	if (dda->ray_diry == 0)
		dda->delta_y = pow(10, 30);
	else
		dda->delta_y = fabs(1 / dda->ray_diry);
	dda->hit = 0;
	get_step_and_sidedist(main, dda);
	dda_main_loop(main, dda);
	get_perpwall_dist(dda);
}
