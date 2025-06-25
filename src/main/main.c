
#include "cub3d.h"

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
	mlx_hook(main->mlx_win, 17, 0, handle_destroy, &main);
	init_img(main);
}

int	main(int argc, char **argv)
{
	t_main	main;

	ft_bzero(&main, sizeof(t_main));
	if (!arguments_are_valid(argc, argv))
		return (EXIT_FAILURE);
	main.player.x = 600;  //debug
	main.player.y = 400; //debug
	init_cub3d(&main);
	parsing(&main, argv[1]);
	printf("MAP HEIGHT %d\n", main.map_struct.height); //debug
	printf("MAP WIDTH %d\n", main.map_struct.width); //debug
	init_keyboard_events(&main);
	mlx_loop_hook(main.mlx_ptr, render_next_frame, &main);
	mlx_loop(main.mlx_ptr);
	return (0);
}
