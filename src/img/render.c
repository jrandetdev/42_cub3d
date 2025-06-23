/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:17:18 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/23 14:50:46 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_main *main)
{
	if (main->keys.w == 1)
		main->player.y -= PLAYER_SPEED;
	else if (main->keys.s == 1)
		main->player.y += PLAYER_SPEED;
	else if (main->keys.a == 1)
		main->player.x -= PLAYER_SPEED;
	else if (main->keys.d == 1)
		main->player.x += PLAYER_SPEED;
	//mlx_clear_window(main->mlx_ptr, main->mlx_win);
	draw_square(main, main->player.x, main->player.y);
	return (0);
}