/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:17:18 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/24 17:20:49 by jrandet          ###   ########.fr       */
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
	//add diagonal ?
	draw_square(main, main->player.x, main->player.y);
	return (0);
}