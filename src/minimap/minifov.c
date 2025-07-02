#include <math.h>
#include "cub3d.h"

static void	print_mini_vector_from_angle(t_main *main, double angle)
{
	double	magnitude;
	double	angle_in_radians;
	t_vec2	vector;

	magnitude = sqrt(pow(main->map_struct.height, 2) + pow(main->map_struct.width, 2)); //max_map_size
	angle_in_radians = angle * M_PI / 180;
	vector.x = main->player.x + (magnitude * cos(angle_in_radians));
	vector.y = main->player.y + (magnitude * sin(angle_in_radians));
	mini_dda(main, vector.x, vector.y);
}

void	print_minifov(t_main *main)
{
	double angle_degrees;

	if (main->player.direction > 360)
		main->player.direction = 0;
	if (main->player.direction < 0)
		main->player.direction = 360;
	angle_degrees = main->player.direction - 45;
	while (angle_degrees < (main->player.direction + 45))
	{
		print_mini_vector_from_angle(main, angle_degrees);
		angle_degrees += 0.1;
	}
}