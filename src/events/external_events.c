
#include "cub3d.h"

int	mouse_move(int x, int y, t_main *main)
{
	//static int old_pos = WIN_WIDTH / 2;

	mlx_mouse_get_pos(main->mlx_ptr, main->mlx_win, &x, &y);
	if (x != main->mouse.x)
	{
		if (x > main->mouse.x)
			main->mouse.dist = (x - main->mouse.x) / 25;
		else
		{
			main->mouse.dist = (main->mouse.x - x) / 25;
			main->mouse.dist = -main->mouse.dist;
		}
		mlx_mouse_move(main->mlx_ptr, main->mlx_win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	// if (main->mouse.dist != old_pos)
	// {
	// 	printf("mouse old pos %d\n", old_pos);
	// 	printf("mouse dist %f\n", main->mouse.dist);
	// }
	//old_pos = main->mouse.dist;
	return (0);
}

static int	key_pressed(int keycode, t_main *main)
{
	if (keycode == K_W)
		main->keys.w = 1;
	if (keycode == K_A)
		main->keys.a = 1;
	if (keycode == K_S)
		main->keys.s = 1;
	if (keycode == K_D)
		main->keys.d = 1;
	if (keycode == K_G)
		main->keys.g = !main->keys.g;
	if (keycode == K_M)
		main->keys.m = !main->keys.m;
	if (keycode == K_LEFT)
		main->keys.left = 1;
	if (keycode == K_RIGHT)
		main->keys.right = 1;
	if (keycode == K_ESCP)
		exit_cub3d(main, 0);
	if (keycode == K_ENTER)
		main->keys.enter = 1;
	if (keycode == K_UP)
		main->keys.up = 1;
	if (keycode == K_DOWN)
		main->keys.down = 1;
	if (main->debug.last_keycode != keycode) //debug
		printf("keycode : %d\n", keycode); //debug
	main->debug.last_keycode = keycode; //debug
	return (1);
}

static int	key_released(int keycode, t_main *main)
{
	if (keycode == K_W)
		main->keys.w = 0;
	if (keycode == K_A)
		main->keys.a = 0;
	if (keycode == K_S)
		main->keys.s = 0;
	if (keycode == K_D)
		main->keys.d = 0;
	if (keycode == K_LEFT)
		main->keys.left = 0;
	if (keycode == K_RIGHT)
		main->keys.right = 0;
	if (keycode == K_ENTER)
		main->keys.enter = 0;
	if (keycode == K_UP)
		main->keys.up = 0;
	if (keycode == K_DOWN)
		main->keys.down = 0;
	return (0);
}



void	init_external_events(t_main *main)
{
	mlx_hook(main->mlx_win, ON_KEYDOWN, 1L << 0, key_pressed, main);
	mlx_hook(main->mlx_win, ON_KEYUP, 1L << 1, key_released, main);
	mlx_hook(main->mlx_win, ON_MOUSEMOVE, 1L<<6, mouse_move, main);
}
