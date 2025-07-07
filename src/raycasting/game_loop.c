
#include "cub3d.h"

static void	raycasting(t_main *main, t_vec2 vector, int x)
{
	int		y;
	double	size;
	int		distance;
	t_vec2	player;

	player.x = main->minimap.start_px + main->player.x * main->minimap.tile_size;
	player.y = main->minimap.start_py + main->player.y * main->minimap.tile_size;
	distance = get_vector_norm(player, vector);
	size = 10000.0 / (distance + 1);
	if (size > WIN_HEIGHT - 5)
		size = WIN_HEIGHT - 5;
	if (size < 1)
		size = 0;
	y = (WIN_HEIGHT/2) - (size/2);
	while (y < ((WIN_HEIGHT/2) - (size/2)) + size)
	{
		put_pixel_to_image(main, x, y, 0xFFFFFF);
		y++;
	}
}

void	cast_rays(t_main *main)
{
	int			x;
	t_vec2		vector;
	t_player	*player;
	
	x = 0;
	player = &main->player;
	while (x < WIN_WIDTH)
	{
		player->camera_x = 2 * x / (double) WIN_WIDTH - 1;
		main->ray.dirX = player->dir_x + player->plane_x * player->camera_x;
		main->ray.dirY = player->dir_y + player->plane_y * player->camera_x;
		vector = digital_differential_analyzer(main);
		raycasting(main, vector, x);
	}
}
