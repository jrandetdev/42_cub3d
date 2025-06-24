/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:17:18 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/24 14:37:23 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_movement(t_main *main)
{
	if (main->keys.w == 1)
		main->player.y -= PLAYER_SPEED;
	if (main->keys.s == 1)
		main->player.y += PLAYER_SPEED;
	if (main->keys.a == 1)
		main->player.x -= PLAYER_SPEED;
	if (main->keys.d == 1)
		main->player.x += PLAYER_SPEED;
}

int	render_next_frame(t_main *main)
{
	mlx_destroy_image(main->mlx_ptr, main->image.data_img);
	init_img(main);
	player_movement(main);
	print_wall(main);
	draw_square(main, main->player.x, main->player.y);
	if (main->keys.g)
		print_grid(main);
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, main->image.data_img, 0, 0);
	return (0);
}