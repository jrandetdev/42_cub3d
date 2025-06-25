
#include "cub3d.h"

int	render_next_frame(t_main *main)
{
	if (main->keys.w == 1)
		main->player.y -= PLAYER_SPEED;
	else if (main->keys.s == 1)
		main->player.y += PLAYER_SPEED;
	else if (main->keys.a == 1)
		main->player.x -= PLAYER_SPEED;
	else if (main->keys.d == 1)
		main->player.x += PLAYER_SPEED;
	//add diagonal ?
	draw_square(main, main->player.x, main->player.y);
	return (0);
}