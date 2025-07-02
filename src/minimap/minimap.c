
#include "cub3d.h"

static void print_minimap_background(t_main *main)
{
	int	x;
	int	y;

	y = main->minimap.start_py;
	while (y <= main->minimap.start_py + main->minimap.map_size_y)
	{
		x = main->minimap.start_px;
		while (x <= main->minimap.start_px + main->minimap.map_size_x)
		{
			put_pixel_to_image(main, x, y, 0x00797b);
			x++;
		}
		y++;
	}
}

void	init_minimap(t_main *main)
{
	main->minimap.tile_size = 10;
	main->minimap.map_size_x = main->map_struct.width * main->minimap.tile_size;
	main->minimap.map_size_y = main->map_struct.height * main->minimap.tile_size;
	main->minimap.start_px = WIN_WIDTH - main->minimap.map_size_x - 10; // -10 is only for "design"
	main->minimap.start_py = WIN_HEIGHT - main->minimap.map_size_y - 10; // -10 is only for "design"
}

void	print_minimap(t_main *main)
{
	init_minimap(main); //init in right file later
	print_minimap_background(main);
	print_obstacles(main);
}