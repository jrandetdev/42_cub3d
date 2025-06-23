/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:39:16 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/23 11:12:31 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_main *main, int start_x, int start_y)
{
	int		size;
	int		x;
	int		y;

	size = 20;
	y = start_y - size;
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
}