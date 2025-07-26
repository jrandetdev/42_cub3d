
#include "cub3d.h"

void	open_door_animation(t_main *main)
{
	static int	i = 0;
	static int	frame = 0;

	if (!(frame % 10))
		i++;
	if (!main->animation.door[i].texture_ptr)
		main->animation_playing = 0;
}
