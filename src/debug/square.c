
#include "cub3d.h"

void	draw_square(t_main *main, double start_x, double start_y)
{
	int		size;
	int		x;
	int		y;

	start_x *= main->debug.tile_size;
	start_y *= main->debug.tile_size;
	size = main->debug.tile_size / 4;
	y = start_y - size;
	while (y <= start_y + size)
	{
		x = start_x - size;
		while (x <= start_x + size)
		{
			put_pixel_to_image(main, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}
