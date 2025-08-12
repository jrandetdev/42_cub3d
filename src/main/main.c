/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:23:58 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/12 14:21:54 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	arguments_are_valid(t_main *main, int argc, char **argv)
{
	if (argc != 2)
		print_error_message(main, "Please give only one file as input.\n");
	else if (!cub_extension_is_valid(argv[1], 3))
		print_error_message(main, ".cub extenssion is missing.\n");
	else if (WIN_HEIGHT < MIN_RESOLTION_Y || WIN_WIDTH < MIN_RESOLUTION_X)
		print_error_message(main, "Resolution too small\n");
}

static void	init_mlx(t_main *main)
{
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		print_error_syscall(main, "Mlx init failed.");
}

static void	init_cub3d(t_main *main)
{
	main->menu = 1;
	main->param.fov = 1;
	main->param.show_minimap = 1;
	main->mouse.sensitivity = 25;
	calcule_constants(main);
	main->mlx_win = mlx_new_window(main->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "Cub3d");
	if (!main->mlx_win)
		print_error_syscall(main, "Mlx window failed");
	init_img(main);
	main->mouse.x = main->cal.half_ww;
	mlx_mouse_hide(main->mlx_ptr, main->mlx_win);
	if (gettimeofday(&main->bonus.last_sec, NULL))
		print_error_syscall(main, "GetTimeOfDay failed in init_cub3d");
	errno = 0;
}

int	main(int argc, char **argv)
{
	t_main	main;

	arguments_are_valid(&main, argc, argv);
	ft_bzero(&main, sizeof(t_main));
	init_mlx(&main);
	parsing(&main, argv[1]);
	init_cub3d(&main);
	init_external_events(&main);
	mlx_hook(main.mlx_win, 17, 0, handle_destroy, &main);
	mlx_loop_hook(main.mlx_ptr, game_loop, &main);
	mlx_loop(main.mlx_ptr);
	return (0);
}
