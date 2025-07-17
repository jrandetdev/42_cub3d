
#include "bonus.h"

void	fps_counter(t_main	*main)
{
	char					*fps_string;
	static int				old_fps = 0;
	struct timeval			tv;
	static unsigned int		fps = 0;
	unsigned int			ms;

	if (gettimeofday(&tv, NULL))
		exit_cub3d(main, "gettimeof day failed");
	fps++;
	ms = (tv.tv_sec - main->bonus.tv.tv_sec) * 1000;
	ms += (tv.tv_usec - main->bonus.tv.tv_usec) / 1000;
	if (ms >= 1000)
	{
		old_fps = fps;
		fps = 0;
		if (gettimeofday(&main->bonus.tv, NULL))
			exit_cub3d(main, "gettimeof day failed");
	}
	fps_string = ft_itoa(old_fps);
	if (!fps_string)
		exit_cub3d(main, "FPS Counter allocation failed");
	mlx_string_put(main->mlx_ptr, main->mlx_win, 10, 10, 0xff0000, fps_string);
}
