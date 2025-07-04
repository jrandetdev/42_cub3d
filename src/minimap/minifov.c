#include <math.h>
#include "cub3d.h"

static void	print_mini_vector_from_angle(t_main *main, double angle)
{
	double	magnitude;
	t_vec2	vector;

	magnitude = sqrt(pow(main->map_struct.height, 2) + pow(main->map_struct.width, 2)); //max_map_size
	vector.x = main->player.x + (magnitude * cos(angle));
	vector.y = main->player.y + (magnitude * sin(angle));
	mini_dda(main, vector.x, vector.y);
}

void	print_minifov(t_main *main)
{
	double	start_fov;
	double	end_fov;

	
	printf("angle degree is worth %f\n", main->player.angle);
	start_fov = main->player.angle - (M_PI / 6);
	end_fov = main->player.angle + M_PI / 6;
	printf("start fov %f\n", start_fov);
	printf("end fov %f\n", end_fov);
	while (start_fov < end_fov)
	{
		print_mini_vector_from_angle(main, start_fov);
		start_fov += 0.001;
	}
}