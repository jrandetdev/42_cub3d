
#include "cub3d.h"
#include <math.h>

void	dda_algo(t_main *main, double dst_x, double dst_y)
{
	int		x;
	int		y;
	//double	m; //angle
	double	dx;
	double	dy;

	//m = x2 - x1;
	dx = (dst_x - main->player.x) * main->debug.tile_size;
	dy = (dst_y - main->player.y) * main->debug.tile_size;
	x = main->player.x * main->debug.tile_size;
	y = main->player.y * main->debug.tile_size;
	for (int i = 0; i < fmax(dx, dy); i++)
	{
		x += fmax(dx, dy) / dx;
		y += fmax(dx, dy) / dy;
		put_pixel_to_image(main, x, y, 0xF4E700); 
	}
}