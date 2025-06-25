/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:06:49 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/24 13:57:12 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../include/cub3d.h"

static void	print_colum(t_main *main, float x)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		put_pixel_to_image(main, x, y, 0xFFFFFF);
		y++;
	}
}

void	print_lines(t_main *main, float y)
{
	int	x;

	x = 0;
	while(x < WIN_WIDTH)
	{
		put_pixel_to_image(main, x, y, 0xFFFFFF);
		x++;
	}
}

void	print_grid(t_main *main)
{
	float	x;
	float	y;

	x = 0;
	y = 0;
	while(x < WIN_WIDTH)
	{
		print_colum(main, x);
		x += main->debug.tile_size;
	}
	while(y < WIN_HEIGHT)
	{
		print_lines(main, y);
		y += main->debug.tile_size;
	}
}