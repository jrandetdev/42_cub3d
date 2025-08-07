/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:23:58 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/07 14:10:38 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
fov / 2
WIN_HEIHT / 2
main->cal.half_ww
M_PI / 2
*/

//FIX WALL

static bool	arguments_are_valid(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error_and_message("Please give only one file as input.\n");
		return (false);
	}
	if (!cub_extension_is_valid(argv[1], 3))
	{
		print_error_and_message(".cub extenssion is missing.\n");
		return (false);
	}
	if (WIN_HEIGHT < MIN_RESOLTION_Y || WIN_WIDTH < MIN_RESOLUTION_X)
	{
		print_error_and_message("Resolution too small\n");
		return (false);
	}
	return (true);
}

static void	init_mlx(t_main *main)
{
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		exit_cub3d(main, "Mlx init failed.");
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
		exit_cub3d(main, "Mlx window failed");
	init_img(main);
	main->mouse.x = main->cal.half_ww;
	mlx_mouse_hide(main->mlx_ptr, main->mlx_win);
	if (gettimeofday(&main->bonus.last_sec, NULL))
		exit_cub3d(main, "GetTimeOfDay failed in init_cub3d");
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (!arguments_are_valid(argc, argv))
		return (EXIT_FAILURE);
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
