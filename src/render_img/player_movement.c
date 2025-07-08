
#include "cub3d.h"

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

static void	valid_next_movement(t_main *main, double x, double y)
{
	if (main->map_struct.map[(int)trunc(y)][(int)trunc(x)] == '0')
	{
		main->player.x = x;
		main->player.y = y;
	}
}

static void	player_right_and_left(t_main *main)
{
	double	new_x;
	double	new_y;

	if (main->keys.d == 1)
	{
		new_x = main->player.x - (main->player.dir_y * PLAYER_SPEED);
		new_y = main->player.y - (main->player.dir_x * PLAYER_SPEED);
		valid_next_movement(main, new_x, new_y);
	}
	if (main->keys.a == 1)
	{
		new_x = main->player.x + (main->player.dir_y * PLAYER_SPEED);
		new_y = main->player.y - (-main->player.dir_x * PLAYER_SPEED);
		valid_next_movement(main, new_x, new_y);
	}
}

static void	player_up_and_down(t_main *main)
{
	double	new_x;
	double	new_y;

	if (main->keys.w == 1)
	{
		new_x = main->player.x + (main->player.dir_x * PLAYER_SPEED);
		new_y = main->player.y + (main->player.dir_y * PLAYER_SPEED);
		valid_next_movement(main, new_x, new_y);
	}
	if (main->keys.s == 1)
	{
		new_x = main->player.x - (main->player.dir_x * PLAYER_SPEED);
		new_y = main->player.y - (main->player.dir_y * PLAYER_SPEED);
		valid_next_movement(main, new_x, new_y);
	}
}

void	player_movement(t_main *main)
{
	player_up_and_down(main);
	player_right_and_left(main);
	player_rotation(main);
}