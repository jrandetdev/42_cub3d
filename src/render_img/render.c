
#include "cub3d.h"
#include <math.h>

// static void	render_fov_player(t_main *main)
// {
// 	double	x;
// 	double	y;

// 	x = main->player.x;
// 	y = main->player.y;
// 	dda_algo(main, x + 1, y + 1);

// }

static void	player_movement(t_main *main)
{
	int	rx;
	int	ry;

	if (main->keys.w == 1)
	{
		rx = main->player.x;
		ry = trunc(main->player.y - PLAYER_SPEED);
		if (main->map_struct.map[ry][rx] == '1')
			main->player.y += 0.01;
		else
			main->player.y -= PLAYER_SPEED;
	}
	if (main->keys.s == 1)
	{
		rx = main->player.x;
		ry = trunc(main->player.y + PLAYER_SPEED);
		if (main->map_struct.map[ry][rx] == '1')
			main->player.y -= 0.01;
		else
			main->player.y += PLAYER_SPEED;
	}
	if (main->keys.a == 1)
	{
		rx = (main->player.x - PLAYER_SPEED);
		ry = main->player.y;
		if (main->map_struct.map[ry][rx] == '1')
			main->player.x += 0.01;
		else
			main->player.x -= PLAYER_SPEED;
	}
	if (main->keys.d == 1)
	{
		rx = (main->player.x + PLAYER_SPEED);
		ry = main->player.y;
		if (main->map_struct.map[ry][rx] == '1')
			main->player.x -= 0.01;
		else
			main->player.x += PLAYER_SPEED;
	}
	if (main->keys.right == 1)
		main->player.angle += ROTATION_SPEED;
	if (main->keys.left == 1)
		main->player.angle -= ROTATION_SPEED;
}

int	render_next_frame(t_main *main)
{
	mlx_destroy_image(main->mlx_ptr, main->image.data_img);
	init_img(main);
	player_movement(main);
	print_wall(main);
	if (main->keys.g)
		print_grid(main);
	//print_vector(main);
	//render_fov_player(main);
	//print_vector_from_angle(main);
	print_fov(main);
	draw_square(main, main->player.x, main->player.y);
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
		main->image.data_img, 0, 0);
	return (0);
}
