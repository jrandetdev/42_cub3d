/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minifov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:28:55 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/12 16:36:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_mini_vector_from_angle(t_main *main, float angle)
{
	float	magnitude;
	t_vec2	vector;

	magnitude = sqrt(pow(main->map_struct.height, 2)
			+ pow(main->map_struct.width, 2));
	vector.x = main->player.x + (magnitude * cos(angle));
	vector.y = main->player.y + (magnitude * sin(angle));
	mini_dda(main, vector.x, vector.y);
}

void	print_minifov(t_main *main)
{
	float	start_fov;
	float	end_fov;

	start_fov = main->player.angle - main->cal.pre_fov;
	end_fov = main->player.angle + main->cal.pre_fov;
	while (start_fov <= end_fov)
	{
		print_mini_vector_from_angle(main, start_fov);
		start_fov += 0.001;
	}
}
