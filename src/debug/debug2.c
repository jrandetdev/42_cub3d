
#include <math.h>
#include "cub3d.h"

void	print_vector(t_main *main)
{
	int		x;
	int		y;
	int		i;
	int		size;
	double	len;

	i = 0;
	x = trunc(main->player.x);
	y = trunc(main->player.y);
	size = main->debug.tile_size;
	while (main->map_struct.map[y][x])
	{
		if (main->map_struct.map[y][x] == '1')
			break ;
		y--;
	}
	len = (main->player.y - y);
	y = main->player.y * size - size / 4;
	while (i < len * size - size - size / 4)
	{
		put_pixel_to_image(main, main->player.x * size, y - i, 0xFFFFFF);
		i++;
	}
	if (len != main->debug.last_vector_size)
	{
		printf("Vector Len : %f\n", len);
		main->debug.last_vector_size = len;
	}
}