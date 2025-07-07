
#include "cub3d.h"

// static void	raycasting(t_main *main, t_vec2 vector, int x)
// {
// 	int		y;
// 	double	size;
// 	int		distance;
// 	t_vec2	player;

// 	player.x = main->minimap.start_px + main->player.x * main->minimap.tile_size;
// 	player.y = main->minimap.start_py + main->player.y * main->minimap.tile_size;
// 	distance = get_vector_norm(player, vector);
// 	size = 10000.0 / (distance + 1);
// 	if (size > WIN_HEIGHT - 5)
// 		size = WIN_HEIGHT - 5;
// 	if (size < 1)
// 		size = 0;
// 	y = (WIN_HEIGHT/2) - (size/2);
// 	while (y < ((WIN_HEIGHT/2) - (size/2)) + size)
// 	{
// 		put_pixel_to_image(main, x, y, 0xFFFFFF);
// 		y++;
// 	}
// }

void	cast_rays(t_main *main)
{
	int			x;
	double		walldist;
	
	x = 0;
	while (x < WIN_WIDTH)
	{
		main->player.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		main->ray.dirX = main->player.dir_x + main->player.plane_x * main->player.camera_x;
		main->ray.dirY = main->player.dir_y + main->player.plane_y * main->player.camera_x;
		walldist = digital_differential_analyzer(main);
		draw_line(main, walldist, x);
		x++;
	}
}
