/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:17:18 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/23 14:10:53 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_main *main)
{
	if (main->keys.w)
		main->player.x += PLAYER_SPEED;
	if (main->player.x)
		main->player.x -= PLAYER_SPEED;
	if (main->keys.a)
		main->player.y -= PLAYER_SPEED;
	if (main->keys.d)
		main->player.y += PLAYER_SPEED;
	mlx_clear_window(main->mlx_ptr, main->mlx_win);
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, main->image.data_img, 0, 0);
	return (0);
}