/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:30:44 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 16:50:53 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_fullscreen_minimap(t_main *main)
{
	int	maxwidth;
	int	maxheight;
	int	tile_size_x;
	int	tile_size_y;

	maxwidth = WIN_WIDTH - 20;
	maxheight = WIN_HEIGHT - 60;
	tile_size_x = maxwidth / main->map.width;
	tile_size_y = maxheight / main->map.height;
	if (tile_size_x < tile_size_y)
		main->minimap.tile_size = tile_size_x;
	else
		main->minimap.tile_size = tile_size_y;
	if (main->minimap.tile_size < 1)
		main->minimap.tile_size = 1;
	main->minimap.map_size_x = main->map.width \
* main->minimap.tile_size;
	main->minimap.map_size_y = main->map.height \
* main->minimap.tile_size;
	main->minimap.start_px = (WIN_WIDTH - main->minimap.map_size_x) / 2;
	main->minimap.start_py = (WIN_HEIGHT - main->minimap.map_size_y) / 2;
}

void	init_minimap(t_main *main)
{
	int	tile_size_x;
	int	tile_size_y;

	tile_size_x = (WIN_WIDTH / 3) / main->map.width;
	tile_size_y = (WIN_HEIGHT / 3) / main->map.height;
	if (tile_size_x < tile_size_y)
		main->minimap.tile_size = tile_size_x;
	else
		main->minimap.tile_size = tile_size_y;
	if (main->minimap.tile_size > 10)
		main->minimap.tile_size = 10;
	main->minimap.map_size_x = main->map.width \
* main->minimap.tile_size;
	main->minimap.map_size_y = main->map.height \
* main->minimap.tile_size;
	main->minimap.start_px = WIN_WIDTH - main->minimap.map_size_x - 10;
	main->minimap.start_py = WIN_HEIGHT - main->minimap.map_size_y - 10;
}

void	print_minimap(t_main *main)
{
	if (main->interaction.keys.m)
		init_fullscreen_minimap(main);
	else
		init_minimap(main);
	print_minimap_base(main);
	if (main->menu.option.fov)
		print_minifov(main);
	draw_player(main);
	if (main->menu.option.show_minimap_grid)
		print_grid(main);
}
