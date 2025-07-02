
#include "cub3d.h"

static void	print_tile(t_main *main, int idx_x, int idx_y, int color)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = main->minimap.start_px + idx_x * main->minimap.tile_size;
	start_y = main->minimap.start_py + idx_y * main->minimap.tile_size;
	y = start_y;
	while (y <= start_y + main->minimap.tile_size)
	{
		x = start_x;
		while (x <= start_x + main->minimap.tile_size)
		{
			put_pixel_to_image(main, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_obstacles(t_main *main)
{
	int	i;
	int	j;

	j = 0;
	while (main->map_struct.map[j])
	{
		i = 0;
		while (main->map_struct.map[j][i])
		{
			if (main->map_struct.map[j][i] == '1')
				print_tile(main, i, j, 0x00007b);
			i++;
		}
		j++;
	}
}