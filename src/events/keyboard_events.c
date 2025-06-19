/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:22:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/19 18:04:50 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int key_code, t_main *main)
{
	mlx_clear_window(main->mlx_ptr, main->mlx_win);
	draw_square(main->mlx_ptr, main->mlx_win, (WIN_WIDTH/2) - 50, (WIN_HEIGHT/2) - 50);//debug
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
