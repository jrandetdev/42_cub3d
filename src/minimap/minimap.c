
#include "cub3d.h"
#include "struct.h"

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

// static void	init_fullscreen_minimap(t_main *main)
// {
// 	main->minimap.map_size_x = (WIN_WIDTH - 20) / main->map_struct.width;
// 	main->minimap.map_size_y = (WIN_HEIGHT - 20) / main->map_struct.height;
// 	main->minimap.start_px = 10;
// 	main->minimap.start_py = 10;
// 	main->minimap.tile_size = main->minimap.map_size_x / main->map_struct.width;
// }

static void	init_fullscreen_minimap(t_main *main)
{
	main->minimap.tile_size = 45; //detect the max map_size
	main->minimap.map_size_x = main->map_struct.width * main->minimap.tile_size;
	main->minimap.map_size_y = main->map_struct.height * main->minimap.tile_size;
	main->minimap.start_px = WIN_WIDTH - main->minimap.map_size_x - 7;
	main->minimap.start_py = WIN_HEIGHT - main->minimap.map_size_y - 55;
}

void	init_minimap(t_main *main)
{
	main->minimap.tile_size = 10; //add this dynamic
	main->minimap.map_size_x = main->map_struct.width * main->minimap.tile_size;
	main->minimap.map_size_y = main->map_struct.height * main->minimap.tile_size;
	main->minimap.start_px = WIN_WIDTH - main->minimap.map_size_x - 10; // -10 is only for "design"
	main->minimap.start_py = WIN_HEIGHT - main->minimap.map_size_y - 10; // -10 is only for "design"
}

void	print_minimap(t_main *main)
{
	if (main->keys.m)
		init_fullscreen_minimap(main);
	else
		init_minimap(main);
	//mini_raycasting(main);
	print_minimap_background(main);
	print_obstacles(main);
	print_minifov(main);
	draw_player(main);
	if (main->keys.g)
			print_grid(main);
	
}