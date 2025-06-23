/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:22:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/23 14:09:29 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_keys(t_main *main)
{
	main->keys.w = 0;
	main->keys.a = 0;
	main->keys.s = 0;
	main->keys.d = 0;
	main->keys.g = 0;
	main->keys.escp = 0;
}

static int	key_pressed(int keycode, t_main *main)
{
	if (keycode == K_W)
		main->keys.w = 1;
	if (keycode == K_A)
		main->keys.a = 1;
	if (keycode == K_S)
		main->keys.s = 1;
	if (keycode == K_D)
		main->keys.d = 1;
	if (keycode == K_G)
		main->keys.g = 1;
	if (keycode == K_ESCP)
		exit_cub3d(main, 0);
	return (1);
}

static int	key_released(int keycode, t_main *main)
{
	if (keycode == K_W)
		main->keys.w = 0;
	if (keycode == K_A)
		main->keys.a = 0;
	if (keycode == K_S)
		main->keys.s = 0;
	if (keycode == K_D)
		main->keys.d = 0;
	if (keycode == K_G)
		main->keys.g = 0;
	return (0);
}

void	init_keyboard_events(t_main *main)
{
	mlx_hook(main->mlx_win, ON_KEYDOWN, 1L<<0, key_pressed, main);
	mlx_hook(main->mlx_win, ON_KEYUP, 1L<<0, key_released, main);

}
