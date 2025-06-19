/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:22:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/19 16:43:16 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int key_code, t_main *main)
{
	mlx_clear_window(main->mlx_ptr, main->mlx_win);
	printf("KEYCODE %d\n", key_code);
	if (key_code == K_W)
	{
		printf("debug ON\n");
		main->debug = 1;
	}
	else if (key_code == K_S)
	{
		printf("debug OFF\n");
		main->debug = 0;
	}
	if (main->debug == 1)
		print_grid(main);
	if (key_code == K_ESCP)
		exit_cub3d(main, 0);
	return (0);
}

void	init_keyboard_events(t_main *main)
{
	mlx_hook(main->mlx_win, ON_KEYDOWN, 1L<<0, key_handler, main);
}
