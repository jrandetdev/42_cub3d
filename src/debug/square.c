
#include "cub3d.h"

void	draw_square(t_main *main, int start_x, int start_y)
{
	int		size;
	int		ray;
	int		x;
	int		y;

	ray = 0;
	size = main->debug.tile_size / 4;
	y = start_y - size;
	(void) ray;
	while(ray <= 50)
	{
		put_pixel_to_image(main, start_x, y - ray, 0xFFFFF);
		ray++;
	}
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