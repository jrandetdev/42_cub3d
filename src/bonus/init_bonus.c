
#include "bonus.h"

void	init_cub3d_bonus(t_main *main)
{
	if (gettimeofday(&main->bonus.tv, NULL))
		exit_cub3d(main, "gettimeof day failed");
}
