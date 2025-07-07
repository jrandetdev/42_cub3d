
#include "cub3d.h"


static void	print_mini_vector_from_angle(t_main *main, double angle)
{
	double	magnitude;
	t_vec2	vector;

	magnitude = sqrt(pow(main->map_struct.height, 2) + pow(main->map_struct.width, 2));
	vector.x = main->player.x + (magnitude * cos(angle));
	vector.y = main->player.y + (magnitude * sin(angle));
	mini_dda(main, vector.x, vector.y);
}

void	print_minifov(t_main *main)
{
	int		x = 0;
	double	start_fov;
	double	end_fov;

	start_fov = main->player.angle - (M_PI / 6);
	end_fov = main->player.angle + M_PI / 6;
	while (start_fov < end_fov)
	{
		print_mini_vector_from_angle(main, start_fov);
		start_fov += 0.001;
		x++;
	}
}