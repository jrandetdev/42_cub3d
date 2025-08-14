/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:23:58 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/14 22:19:42 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_main	main;

	ft_bzero(&main, sizeof(t_main));
	init_all(&main, argc, argv);
	parsing(&main, argv[1]);
	printf("parsing is ok\n");
	init_mmlx_window_and_mouse(&main);
	init_external_events(&main);
	mlx_loop_hook(main.mlx_ptr, game_loop, &main);
	mlx_loop(main.mlx_ptr);
	return (0);
}
