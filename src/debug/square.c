/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:39:16 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/23 15:10:34 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_main *main, int start_x, int start_y)
{
	int		size;
	int		ray;
	int		x;
	int		y;

	ray = 0;
	size = 20;
	y = start_y - size;
	(void) ray;
	// while(ray <= 30)
	// {
	// 	put_pixel_to_image(main, start_x, y - ray);
	// 	ray++;
	// }
	while (y <= start_y + size)
	{
		x = start_x - size;
		while (x <= start_x + size)
		{
			put_pixel_to_image(main, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, main->image.data_img, 0, 0);
}