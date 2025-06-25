
#include "cub3d.h"


static void	print_tile(t_main *main, int idx_x, int idx_y)
{
	int x;
	int	y;
	int	start_x;

	y = idx_y * main->debug.tile_size;
	start_x = idx_x * main->debug.tile_size;
	while(y < idx_y * main->debug.tile_size + main->debug.tile_size)
	{
		x = start_x;
		while (x < start_x + main->debug.tile_size)
		{
			put_pixel_to_image(main, x, y, 0x4A8BAD);
			x++;
		}
		y++;
	}
}

void	print_wall(t_main *main)
{
	int	i;
	int	j;

	j = 0;
	while(main->map_struct.map[j])
	{
		i = 0;
		while(main->map_struct.map[j][i])
		{
			if (main->map_struct.map[j][i] == '1')
			{
				print_tile(main, i, j);
			}
			i++;
		}
		j++;
	}
}

static void	get_tile_size(t_main *main)
{
	if (main->map_struct.height > main->map_struct.width)
	{
		main->debug.tile_size = WIN_HEIGHT / main->map_struct.height;
	}
	else
	{
		main->debug.tile_size = WIN_WIDTH / main->map_struct.width;	
	}
}

void	init_debug(t_main *main)
{
	get_tile_size(main);
	main->player.x *= main->debug.tile_size; //The player is not centered, is at the top right of his square.
	main->player.y *= main->debug.tile_size;
}

void	print_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}