
 #include "cub3d.h"

void	draw_player(t_main *main)
{
	int	x;
	int	y;
	int	size;
	int	center_x;
	int	center_y;

	size = main->minimap.tile_size / 3;
	center_y = main->minimap.start_py + main->player.y * main->minimap.tile_size;
	center_x = main->minimap.start_px + main->player.x * main->minimap.tile_size;
	y = center_y - size;
	while (y <= center_y + size)
	{
		x = center_x - size;
		while (x <= center_x + size)
		{
			put_pixel_to_image(main, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}


