/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:06:37 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/29 16:08:19 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	backgroud_color(t_main *main)
// {
// 	int	x;
// 	int	y;
// 	int	midle;

// 	y = 0;
// 	midle = main->cal.half_wh;
// 	while (y <= midle)
// 	{
// 		x = 0;
// 		while (x <= WIN_WIDTH)
// 			put_pixel_to_image(main, x++, y, main->f_colour.value);
// 		y++;
// 	}
// 	while (y < WIN_HEIGHT)
// 	{
// 		x = 0;
// 		while (x <= WIN_WIDTH)
// 			put_pixel_to_image(main, x++, y, main->c_colour.value);
// 		y++;
// 	}
// }

int	render_next_frame(t_main *main)
{
	if (main->menu)
	{
		print_correct_menu(main, &main->menu);
		return (0);
	}
	mlx_destroy_image(main->mlx_ptr, main->image.data_img);
	init_img(main);
	if (!main->animation_playing)
		player_movement(main);
	//backgroud_color(main);
	cast_rays(main);
	if (main->param.show_minimap)
		print_minimap(main);
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
		main->image.data_img, 0, 0);
	if (main->param.show_fps)
		fps_counter(main);
	return (0);
}
