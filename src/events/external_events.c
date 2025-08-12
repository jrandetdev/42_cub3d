/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:52:16 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/12 18:02:05 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_main *main)
{
	mlx_mouse_get_pos(main->mlx_ptr, main->mlx_win, &x, &y);
	if (x != main->interaction.mouse.x)
	{
		if (x > main->interaction.mouse.x)
			main->interaction.mouse.dist = (x - main->interaction.mouse.x)
				/ (MAX_SENSITIVITY - main->interaction.mouse.sensitivity + 1);
		else
		{
			main->interaction.mouse.dist = (main->interaction.mouse.x - x)
				/ (MAX_SENSITIVITY - main->interaction.mouse.sensitivity + 1);
			main->interaction.mouse.dist = -main->interaction.mouse.dist;
		}
		mlx_mouse_move(main->mlx_ptr, main->mlx_win,
			main->cal.half_ww, main->cal.half_wh);
	}
	return (0);
}

static void	key_hit(int keycode, t_main *main)
{
	if (keycode == K_ESCP)
		exit_cub3d(main, 0);
	else if (keycode == K_G)
		main->interaction.keys.g = !main->interaction.keys.g;
	else if (keycode == K_M)
		main->interaction.keys.m = !main->interaction.keys.m;
	else if (keycode == K_P && main->game_start && !main->menu)
	{
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
		main->menu = PAUSE_MENU;
	}
	else if (keycode == K_P && main->game_start && main->menu > 0)
		main->menu = NO_MENU;
}

static int	key_pressed(int keycode, t_main *main)
{
	if (keycode == K_W)
		main->interaction.keys.w = 1;
	else if (keycode == K_A)
		main->interaction.keys.a = 1;
	else if (keycode == K_S)
		main->interaction.keys.s = 1;
	else if (keycode == K_D)
		main->interaction.keys.d = 1;
	else if (keycode == K_E)
		main->interaction.keys.e = 1;
	else if (keycode == K_LEFT)
		main->interaction.keys.left = 1;
	else if (keycode == K_RIGHT)
		main->interaction.keys.right = 1;
	else if (keycode == K_ENTER)
		main->interaction.keys.enter = 1;
	else if (keycode == K_UP)
		main->interaction.keys.up = 1;
	else if (keycode == K_DOWN)
		main->interaction.keys.down = 1;
	else if (keycode == K_SHIFT)
		main->interaction.keys.shift = 1;
	key_hit(keycode, main);
	return (1);
}

static int	key_released(int keycode, t_main *main)
{
	if (keycode == K_W)
		main->interaction.keys.w = 0;
	else if (keycode == K_A)
		main->interaction.keys.a = 0;
	else if (keycode == K_S)
		main->interaction.keys.s = 0;
	else if (keycode == K_D)
		main->interaction.keys.d = 0;
	else if (keycode == K_E)
		main->interaction.keys.e = 0;
	else if (keycode == K_LEFT)
		main->interaction.keys.left = 0;
	else if (keycode == K_RIGHT)
		main->interaction.keys.right = 0;
	else if (keycode == K_ENTER)
		main->interaction.keys.enter = 0;
	else if (keycode == K_UP)
		main->interaction.keys.up = 0;
	else if (keycode == K_DOWN)
		main->interaction.keys.down = 0;
	else if (keycode == K_SHIFT)
		main->interaction.keys.shift = 0;
	return (0);
}

void	init_external_events(t_main *main)
{
	mlx_hook(main->mlx_win, ON_KEYDOWN, 1L << 0, key_pressed, main);
	mlx_hook(main->mlx_win, ON_KEYUP, 1L << 1, key_released, main);
	mlx_hook(main->mlx_win, ON_MOUSEMOVE, 1L << 6, mouse_move, main);
}
