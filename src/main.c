/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:23:58 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/14 10:14:29 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_main	main;

	init_all(&main, argc, argv);
	parsing(&main, argv[1]);
	mlx_hook(main.mlx_win, 17, 0, handle_destroy, &main);
	mlx_loop_hook(main.mlx_ptr, game_loop, &main);
	mlx_loop(main.mlx_ptr);
	return (0);
}
