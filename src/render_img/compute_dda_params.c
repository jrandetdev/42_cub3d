/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_dda_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:40:02 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:40:58 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	compute_delta_and_step(float ray_comp, float *delta_in_dir,\
	int *step_in_dir);
static void	get_delta_value(float ray_component, float *delta_in_direction);
static void	get_step_in_direction(float ray_component, int *step_in_direction);
static void	compute_dist_to_intercept(t_main *main, t_dda *dda);

void	set_dda_params(t_main *main, t_dda *dda)
{
	dda->x = main->player.x;
	dda->y = main->player.y;
	dda->hit = 0;
	compute_delta_and_step(dda->ray.x, &dda->delta_x, &dda->step_x);
	compute_delta_and_step(dda->ray.y, &dda->delta_y, &dda->step_y);
	compute_dist_to_intercept(main, dda);
}

static void	compute_delta_and_step(float ray_comp, float *delta_in_dir,\
	int *step_in_dir)
{
	get_delta_value(ray_comp, delta_in_dir);
	get_step_in_direction(ray_comp, step_in_dir);
}

static void	get_delta_value(float ray_component, float *delta_in_direction)
{
	if (ray_component == 0)
		*delta_in_direction = pow(10, 30);
	else
		*delta_in_direction = fabs(1 / ray_component);
}

static void	get_step_in_direction(float ray_component, int *step_in_direction)
{
	if (ray_component < 0)
		*step_in_direction = -1;
	else
		*step_in_direction = 1;
}

static void	compute_dist_to_intercept(t_main *main, t_dda *dda)
{
	if (dda->ray.x < 0)
		dda->dist_to_x_int = (main->player.x - dda->x) * dda->delta_x;
	else
		dda->dist_to_x_int = (dda->x + 1.0 - main->player.x) * dda->delta_x;
	if (dda->ray.y < 0)
		dda->dist_to_y_int = (main->player.y - dda->y) * dda->delta_y;
	else
		dda->dist_to_y_int = (dda->y + 1.0 - main->player.y) * dda->delta_y;
}
