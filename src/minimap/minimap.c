/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:30:44 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/22 15:31:34 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct.h"

static void	init_fullscreen_minimap(t_main *main)
{
	main->minimap.tile_size = WIN_WIDTH / main->map_struct.width;
	main->minimap.map_size_x = main->map_struct.width * main->minimap.tile_size;
	main->minimap.map_size_y = main->map_struct.height
		* main->minimap.tile_size;
	main->minimap.start_px = WIN_WIDTH - main->minimap.map_size_x - 7;
	main->minimap.start_py = WIN_HEIGHT - main->minimap.map_size_y - 55;
}

void	init_minimap(t_main *main)
{
	main->minimap.tile_size = 10;
	main->minimap.map_size_x = main->map_struct.width * main->minimap.tile_size;
	main->minimap.map_size_y = main->map_struct.height
		* main->minimap.tile_size;
	main->minimap.start_px = WIN_WIDTH - main->minimap.map_size_x - 10;
	main->minimap.start_py = WIN_HEIGHT - main->minimap.map_size_y - 10;
}

void	print_minimap(t_main *main)
{
	if (main->keys.m)
		init_fullscreen_minimap(main);
	else
		init_minimap(main);
	print_minimap_base(main);
	print_minifov(main);
	draw_player(main);
	if (main->keys.g)
		print_grid(main);
}
