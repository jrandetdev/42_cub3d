
#include <math.h>
#include "cub3d.h"

void	print_vector_from_angle(t_main *main, double angle)
{
	int size = main->debug.tile_size;
	double	magnitude;
	double	angle_in_radians;
	t_vec2	vector;

	(void) size;
	magnitude = 50.0;
	angle_in_radians = angle * M_PI / 180;
	vector.x = main->player.x + (magnitude * cos(angle_in_radians));
	vector.y = main->player.y + (magnitude * sin(angle_in_radians));
	digital_differential_analyzer(main, vector.x, vector.y);
}

void	print_fov(t_main *main)
{
	double	angle_degrees;

	angle_degrees = main->player.angle - 45;
	while (angle_degrees < (main->player.angle + 45))
	{
		print_vector_from_angle(main, angle_degrees);
		angle_degrees += 0.1;
	}
}

// void	print_vector(t_main *main)
// {
// 	int		x;
// 	int		y;
// 	int		i;
// 	int		size;
// 	double	len;

// 	i = 0;
// 	x = trunc(main->player.x);
// 	y = trunc(main->player.y);
// 	size = main->debug.tile_size;
// 	while (main->map_struct.map[y][x])
// 	{
// 		if (main->map_struct.map[y][x] == '1')
// 			break ;
// 		y--;
// 	}
// 	len = (main->player.y - y);
// 	y = main->player.y * size - size / 4;
// 	while (i < len * size - size - size / 4)
// 	{
// 		put_pixel_to_image(main, main->player.x * size, y - i, 0xFFFFFF);
// 		i++;
// 	}
// 	if (len != main->debug.last_vector_size)
// 	{
// 		printf("Vector Len : %f\n", len);
// 		main->debug.last_vector_size = len;
// 	}
// }