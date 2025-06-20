/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:39:16 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/20 16:21:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_main *main, int start_x, int	start_y)
{
	int		x = start_x;
	int		y = start_y;
	int	end_x = start_x + 100;
	int	end_y = start_y + 100;

	while(end_y > y)
	{
		while (end_x > x)
		{
			//mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xFFFFF);
			put_pixel_to_image(main, x, y);
			x++;
		}
		x = start_x;
		y++;
	}
}