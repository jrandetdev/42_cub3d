
#include "cub3d.h"

void	cast_rays(t_main *main)
{
	int			x;
	t_player	*player;
	
	x = 0;
	player = &main->player;
	while (x < WIN_WIDTH)
	{
		player->camera_x = 2 * x / WIN_WIDTH - 1;
		main->ray.dirX = player->dir_x + player->plane_x * player->camera_x;
		main->ray.dirY = player->dir_y + player->plane_y * player->camera_x;
		printf("raydix %f an raydirY is %f\n", main->ray.dirX, main->ray.dirY);
		x++;
	}
}
