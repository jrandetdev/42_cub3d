/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:27:08 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/19 17:11:34 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

//floodfill
	// faire un floodfill 
	//point de depart, un seul N S W E 
		// toutes conditions a respecter 
		//si c'est un V, si c'est un mur, ou un esapce
		//jamais atteindrele /0 et jamais un index -1 
		//condition d'arret: tout ce qui n'est pas 1 (si 0 a la fin de la map)

static bool	cub_extension_is_valid(char	*s, int len)
{
	while (*s)
		s++;
	s--;
	if (*s != 'b')
		return (false);
	while (len--)
		s--;
	if (ft_strncmp(s, ".cub", 4) == 0)
		return (true);
	return (false);
}

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
	return (true);
}

static void	init_cub3d(t_main *main)
{
	main->mlx_ptr = mlx_init();
	if (!main->mlx_ptr)
		exit_cub3d(main, 1);
	main->mlx_win = mlx_new_window(main->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Random title");
	if (!main->mlx_win)
		exit_cub3d(main, 1);
	init_img(main);
}

int	main(int argc, char **argv)
{
	t_main	main;

	ft_bzero(&main, sizeof(t_main));
	if (!arguments_are_valid(argc, argv))
		return (EXIT_FAILURE);
	parsing(&main, argv[1]);
	init_cub3d(&main);
	init_keyboard_events(&main);
	draw_square(main.mlx_ptr, main.mlx_win, (WIN_WIDTH/2) - 50, (WIN_HEIGHT/2) - 50);
	mlx_hook(main.mlx_win, 2, 1L<<0, key_handler, &main);
	mlx_loop(main.mlx_ptr);
	return (0);
}

