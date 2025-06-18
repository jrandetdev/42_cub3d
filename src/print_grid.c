/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:06:49 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/18 14:25:58 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../include/cub3d.h"

static void	print_colum(t_main *main, int x)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		mlx_pixel_put(main->mlx_ptr, main->mlx_win, x, y, 0xFFFFF);
		y++;
	}
}

void	print_lines(t_main *main, int y)
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
	int x;
	int	y;
	int	separator;

	separator = 100;
	x = 0;
	y = 0;
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