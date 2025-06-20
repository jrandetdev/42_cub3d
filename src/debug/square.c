/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:39:16 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/20 15:10:39 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	draw_square(void *mlx_ptr, void *mlx_win, int start_x, int	start_y) //debug
{
	int		x = start_x;
	int		y = start_y;
	int	end_x = start_x + 65;
	int	end_y = start_y + 65;

	while(end_y > y)
	{
		while (end_x > x)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xFF0000);
			x++;
		}
		x = start_x;
		y++;
	}
	for(int i = 0; i < 50; i++)
		mlx_pixel_put(mlx_ptr, mlx_win, start_x + 32, start_y - 2 - i, 0xFFFFFF);
}