
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

static void	player_rotation(t_main *main)
{
	if (main->keys.left == 1)
	{
		main->player.angle -= ROTATION_SPEED;
		if (main->player.angle < 0)
			main->player.angle += 2 * M_PI;
		main->player.dir_x = cos(main->player.angle);
		main->player.dir_y = sin(main->player.angle);
	}
	if (main->keys.right == 1)
	{
		main->player.angle += ROTATION_SPEED;
		if (main->player.angle > 2 * M_PI)
			main->player.angle -= 2 * M_PI;
		main->player.dir_x = cos(main->player.angle);
		main->player.dir_y = sin(main->player.angle);
	}
}

static void	player_movement(t_main *main)
{
	if (main->keys.w == 1)
	{
		main->player.x += (main->player.dir_x * PLAYER_SPEED);
		main->player.y += (main->player.dir_y * PLAYER_SPEED);
	}
	if (main->keys.s == 1)
	{
		main->player.x -= (main->player.dir_x * PLAYER_SPEED);
		main->player.y -= (main->player.dir_y * PLAYER_SPEED);
	}
	if (main->keys.d == 1)
	{
		main->player.x += (main->player.plane_x * PLAYER_SPEED);
		main->player.y += (main->player.plane_y * PLAYER_SPEED);
	}
	if (main->keys.a == 1)
	{
		main->player.x -= (main->player.plane_x * PLAYER_SPEED);
		main->player.y -= (main->player.plane_y * PLAYER_SPEED);
	}
}

int	render_next_frame(t_main *main)
{
	mlx_destroy_image(main->mlx_ptr, main->image.data_img);
	init_img(main);
	player_movement(main);
	player_rotation(main);
	cast_rays(main);
	backgroud_color(main);

	// k_m = 1 show minimap
	print_minimap(main);
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
		main->image.data_img, 0, 0);
	return (0);
}
