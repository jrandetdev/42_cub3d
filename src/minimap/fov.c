
#include <math.h>
#include "cub3d.h"

void	print_vector_from_angle(t_main *main, double direction)
{
	int size = main->debug.tile_size;
	double	magnitude;
	t_vec2	vector;

	(void) size;
	magnitude = 50.0;
	vector.x = main->player.x + (magnitude * cos(direction));
	vector.y = main->player.y + (magnitude * sin(direction));
	digital_differential_analyzer(main, vector.x, vector.y);
}

void	print_fov(t_main *main)
{
	double	max_fov;
	double	temp_player_fov;

	temp_player_fov = main->player.direction;
	max_fov = temp_player_fov + (M_PI / 4);
	temp_player_fov -= M_PI / 4;
	while (temp_player_fov <= max_fov)
	{
		print_vector_from_angle(main, temp_player_fov);
		temp_player_fov += ((M_PI / 2) / WIN_WIDTH);
	}
}
