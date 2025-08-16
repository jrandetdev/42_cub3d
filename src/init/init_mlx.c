/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:06:13 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/16 15:27:16 by hdougoud         ###   ########.fr       */
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
	main->interaction.mouse.is_hide = 1;
	errno = 0;
}
