/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:39:16 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/18 13:46:49 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	draw_square(void *mlx_ptr, void *mlx_win, int start_x, int	start_y)
{
	int		x = start_x;
	int		y = start_y;
	int	end_x = start_x + 20;
	int	end_y = start_y + 20;

	while(end_y > y)
	{
		while (end_x > x)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xFFFFF);
			x++;
		}
		x = start_x;
		y++;
	}
}