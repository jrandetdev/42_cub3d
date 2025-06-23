/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:06:49 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/23 16:16:27 by hdougoud         ###   ########.fr       */
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
		mlx_pixel_put(main->mlx_ptr, main->mlx_win, x, y, 0xFFFFF);
		y++;
	}
}

void	print_lines(t_main *main, float y)
{
	int	x;

	x = 0;
	while(x < WIN_WIDTH)
	{
		mlx_pixel_put(main->mlx_ptr, main->mlx_win, x, y, 0xFFFFF);
		x++;
	}
}

void	print_grid(t_main *main)
{
	float	x;
	float	y;
	float	separator;

	
	x = 0;
	y = 0;
	if (main->map_struct.height < main->map_struct.width)
		separator = WIN_HEIGHT / main->map_struct.height;
	else
		separator = WIN_WIDTH / main->map_struct.width;
	while(x < WIN_WIDTH)
	{
		print_colum(main, x);
		x += separator;
	}
	while(y < WIN_HEIGHT)
	{
		print_lines(main, y);
		y += separator;
	}
}