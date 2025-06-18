/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:27:08 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/18 17:11:36 by hdougoud         ###   ########.fr       */
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

void	draw_square(void *mlx_ptr, void *mlx_win, int start_x, int	start_y) //DEBUG
{
	int		x = start_x;
	int		y = start_y;
	int	end_x = start_x + 100;
	int	end_y = start_y + 100;

	while(end_y > y)
	{
		while (end_x > x)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xFFFFFF);
			x++;
		}
		x = start_x;
		y++;
	}
}

int	keyhandler(int keycode, t_main *main)
{
	(void) main;
	(void) keycode;
	if (keycode == W)
		printf("W\n");
	else
		printf("Hello\n");
	return (0);
}

int main(int argc, char **argv)
{
	t_main	main;

	ft_bzero(&main, sizeof(t_main));
	if (!arguments_are_valid(argc, argv))
		return (EXIT_FAILURE);
	parsing(&main, argv[1]);
	main.mlx_ptr = mlx_init();
	main.mlx_win = mlx_new_window(main.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Random title");
	draw_square(main.mlx_ptr, main.mlx_win, (WIN_WIDTH/2) - 50, (WIN_HEIGHT/2) - 50);
	print_grid(&main);
	mlx_hook(main.mlx_win, 2, 1L<<0, keyhandler, &main);
	mlx_loop(main.mlx_ptr);
	return (0);
}

