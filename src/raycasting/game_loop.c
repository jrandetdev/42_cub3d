
#include "cub3d.h"

// static void	print_pixel_line(t_main *main, int x, double size)
// {
// 	int	y;
// 	int	start_y;

// 	size *= 50;
// 	// if (size <= 2)
// 	// {
// 	// 	y = 0;
// 	// 	while (y < WIN_HEIGHT)
// 	// 	{
// 	// 		put_pixel_to_image(main, x, y, 0xFFFFFF);
// 	// 		y++;
// 	// 	}
// 	// 	return ;
// 	// }
// 	start_y = (WIN_HEIGHT / 2) + (size / 2);
// 	y = start_y;
// 	while (y < size)
// 	{
// 		put_pixel_to_image(main, x, y, 0xFFFFFF);
// 		y++;
// 	}

// }

void	cast_rays(t_main *main)
{
	int			x;
	t_vec2		vector_wall;
	t_vec2		vector_player;
	double		vector_size;
	t_player	*player;
	
	x = 0;
	player = &main->player;
	vector_player.x = main->player.x;
	vector_player.y = main->player.y;
	while (x < WIN_WIDTH)
	{
		player->camera_x = 2 * x / WIN_WIDTH - 1;
		main->ray.dirX = player->dir_x + player->plane_x * player->camera_x;
		main->ray.dirY = player->dir_y + player->plane_y * player->camera_x;
		vector_wall = digital_differential_analyzer(main);
		vector_size = get_vector_norm(vector_player, vector_wall);
		//print_pixel_line(main, x, vector_size);
		printf("SRC %f %f\n", main->player.x, main->player.y);
		printf("DST %f %f\n", vector_wall.x, vector_wall.y);
		printf("SIZE %d %f\n", x, vector_size);
		(void) vector_size;
		x++;
	}
}
