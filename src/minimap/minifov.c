/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minifov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:28:55 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/22 15:51:11 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_mini_vector_from_angle(t_main *main, double angle)
{
	double	magnitude;
	t_vec2	vector;

	magnitude = sqrt(pow(main->map_struct.height, 2)
		+ pow(main->map_struct.width, 2));
	vector.x = main->player.x + (magnitude * cos(angle));
	vector.y = main->player.y + (magnitude * sin(angle));
	mini_dda(main, vector.x, vector.y);
}

void	print_minifov(t_main *main)
{
	double	start_fov;
	double	end_fov;

	start_fov = main->player.angle - (FOV / 2) * (M_PI / 180);
	end_fov = main->player.angle + (FOV / 2) * (M_PI / 180);
	while (start_fov <= end_fov)
	{
		print_mini_vector_from_angle(main, start_fov);
		start_fov += 0.001;
	}
}
 