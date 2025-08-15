/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:06:13 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 19:35:38 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_ptr(t_main *main)
{
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		print_error_syscall(main, "Mlx init failed.");
}

void	init_mlx_window_and_mouse(t_main *main)
{
	main->mlx_win = mlx_new_window(main->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "Cub3d");
	if (!main->mlx_win)
		print_error_syscall(main, "Mlx window failed");
	mlx_mouse_hide(main->mlx_ptr, main->mlx_win);
	errno = 0;
}
