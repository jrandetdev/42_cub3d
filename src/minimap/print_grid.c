/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:01 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/01 23:32:00 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"

static void	print_colum(t_main *main, int x)
{
	int	y;

	y = main->minimap.start_py;
	while (y < main->minimap.start_py + main->minimap.map_size_y)
	{
		put_pixel_to_image(main, x, y, 0xFFFFFF);
		y++;
	}
}

static void	print_lines(t_main *main, int y)
{
	int	x;

	x = main->minimap.start_px;
	while (x < main->minimap.start_px + main->minimap.map_size_x)
	{
		put_pixel_to_image(main, x, y, 0xFFFFFF);
		x++;
	}
}

void	print_grid(t_main *main)
{
	int	x;
	int	y;

	x = main->minimap.start_px;
	y = main->minimap.start_py;
	while (x <= main->minimap.start_px + main->minimap.map_size_x)
	{
		print_colum(main, x);
		x += main->minimap.tile_size;
	}
	while (y <= main->minimap.start_py + main->minimap.map_size_y)
	{
		print_lines(main, y);
		y += main->minimap.tile_size;
	}
}
