
#include "cub3d.h"
#include <math.h>

static void	 backgroud_color(t_main *main)
{
	int	x;
	int	y;
	int	midle;

	y = 0;
	midle = WIN_HEIGHT / 2;
	while (y <= midle)
	{
		x = 0;
		while (x <= WIN_WIDTH)
			put_pixel_to_image(main, x++, y, 0x0b5e0b);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x <= WIN_WIDTH)
			put_pixel_to_image(main, x++, y, 0x47007b);
		y++;
	}
}

// static void	player_movement(t_main *main)
// {
// 	double radian;

// 	radian = main->player.direction * (M_PI / 180);
// 	if (main->keys.w == 1)
// 	{
// 		main->player.x += (PLAYER_SPEED * cos(radian));
// 		main->player.y += (PLAYER_SPEED * sin(radian));
// 	}
// 	if (main->keys.s == 1)
// 	{
// 		main->player.x -= (PLAYER_SPEED * cos(radian));
// 		main->player.y -= (PLAYER_SPEED * sin(radian));
// 	}
// 	if (main->keys.a == 1)
// 	{
// 		main->player.x += (PLAYER_SPEED * cos(main->player.direction * (M_PI / 90)));
// 		main->player.y += (PLAYER_SPEED * sin(main->player.direction * (M_PI / 90)));
// 	}
// 	if (main->keys.d == 1)
// 	{
// 		main->player.x -= (PLAYER_SPEED * cos(main->player.direction * (M_PI / 90)));
// 		main->player.y -= (PLAYER_SPEED * sin(main->player.direction * (M_PI / 90)));
// 	}
// 	if (main->keys.right == 1)
// 		main->player.direction += ROTATION_SPEED;
// 	if (main->keys.left == 1)
// 		main->player.direction -= ROTATION_SPEED;
// }

static void	player_movement(t_main *main)
{
	if (main->keys.w == 1)
	{
		main->player.x += (main->player.forward_x * PLAYER_SPEED);
		printf("main->player.x is worth %f\n", main->player.x);
		main->player.y += (main->player.forward_y * PLAYER_SPEED);
	}
	if (main->keys.s == 1)
	{
		main->player.x -= (main->player.forward_x * PLAYER_SPEED);
		main->player.y -= (main->player.forward_y * PLAYER_SPEED);
	}
	if (main->keys.d == 1)
	{
		main->player.x += (main->player.right_x * PLAYER_SPEED);
		main->player.y += (main->player.right_y * PLAYER_SPEED);
	}
	if (main->keys.a == 1)
	{
		main->player.x -= (main->player.right_x * PLAYER_SPEED);
		main->player.y -= (main->player.right_y * PLAYER_SPEED);
	}
}

int	render_next_frame(t_main *main)
{
	mlx_destroy_image(main->mlx_ptr, main->image.data_img);
	init_img(main);
	player_movement(main);
	backgroud_color(main);
	// k_m = 1 show minimap
	print_minimap(main);
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
		main->image.data_img, 0, 0);
	return (0);
}
