/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:06:37 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 23:55:25 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	backgroud_color(t_main *main)
{
	int	x;
	int	y;

	y = 0;
	if (!main->assets.texture_bank.ceiling.ptr)
	{
		while (y <= WIN_HEIGHT / 2)
		{
			x = 0;
			while (x <= WIN_WIDTH)
				put_pixel_to_image(main, x++, y, main->assets.c_colour.value);
			y++;
		}
	}
	y = WIN_HEIGHT / 2;
	if (!main->assets.texture_bank.floor.ptr)
	{
		while (y < WIN_HEIGHT)
		{
			x = 0;
			while (x <= WIN_WIDTH)
				put_pixel_to_image(main, x++, y, main->assets.f_colour.value);
			y++;
		}
	}
}

int	game_loop(t_main *main)
{
	if (main->menu)
	{
		print_correct_menu(main, &main->menu);
		return (0);
	}
	mlx_destroy_image(main->mlx_ptr, main->image.data_img);
	init_img(main);
	if (!main->assets.door.state)
		player_movement(main);
	else
		playing_door_animation(main);
	backgroud_color(main);
	cast_rays(main);
	if (main->param.show_minimap)
		print_minimap(main);
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
		main->image.data_img, 0, 0);
	if (main->param.show_fps)
		fps_counter(main);
	return (0);
}
