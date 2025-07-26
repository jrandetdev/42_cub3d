/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:55:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/26 21:05:06 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_main *main)
{
	int				x;
	t_dda_struct	dda_struct;
	t_texture		cardinal_texture;

	x = 0;
	draw_floor(main);
	draw_ceiling(main);
	while (x < WIN_WIDTH)
	{
		main->player.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		main->ray.dirX = main->player.dir_x
			+ main->player.plane_x * main->player.camera_x;
		main->ray.dirY = main->player.dir_y
			+ main->player.plane_y * main->player.camera_x;
		digital_differential_analyzer(main, &dda_struct);
		cardinal_texture = get_corresp_texture(main, &dda_struct);
		draw_texture(main, &dda_struct, x, cardinal_texture);
		x++;
	}
}
