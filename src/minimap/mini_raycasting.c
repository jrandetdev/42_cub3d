
#include "cub3d.h"

static void	raycasting(t_main *main, t_vec2 vector, int x)
{
	int		y;
	double	size;
	int		distance;
	t_vec2	player;

	player.x = main->minimap.start_px + main->player.x * main->minimap.tile_size;
	player.y = main->minimap.start_py + main->player.y * main->minimap.tile_size;
	distance = get_vector_norm(player, vector);
	size = 4000.0 / (distance + 1);
	if (size > WIN_HEIGHT - 5)
		size = WIN_HEIGHT - 5;
	if (size < 1)
		size = 0;
	y = (WIN_HEIGHT/2) - (size/2);
	while (y < ((WIN_HEIGHT/2) - (size/2)) + size)
	{
		put_pixel_to_image(main, x, y, 0xFFFFFF);
		y++;
	}
}

static void	print_mini_vector_from_angle(t_main *main, double angle, int x)
{
	double	magnitude;
	t_vec2	vector;
	t_vec2	hited_point;

	magnitude = sqrt(pow(main->map_struct.height, 2) + pow(main->map_struct.width, 2));
	vector.x = main->player.x + (magnitude * cos(angle));
	vector.y = main->player.y + (magnitude * sin(angle));
	hited_point = mini_dda(main, vector.x, vector.y);
	raycasting(main, hited_point, x);
}

void	mini_raycasting(t_main *main)
{
	int		x = 0;
	double	start_fov;
	double	end_fov;

	start_fov = main->player.angle - (M_PI / 6);
	end_fov = main->player.angle + M_PI / 6;
	while (start_fov < end_fov)
	{
		print_mini_vector_from_angle(main, start_fov, x);
		start_fov += 0.001;
		x++;
	}
}