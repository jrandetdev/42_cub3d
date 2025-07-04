
#include "cub3d.h"
#include <math.h>

typedef struct s_dda
{
	double	m;
	double	x_1;
	double	y_1;
	double	x_2;
	double	y_2;
	double	delta_x;
	double	delta_y;
}	t_dda;

void	dda_case_1(t_main *main, t_dda *dda_struct)
{
	int		count_steps;
	int		step_in_x;
	double	x;
	double	y;

	x = dda_struct->x_1;
	y = dda_struct->y_1;
	count_steps = fabs(dda_struct->delta_x);
	if (dda_struct->delta_x > 0)
		step_in_x = 1;
	else
		step_in_x = -1;
	while (count_steps > 0)
	{
		int	xm = x / main->debug.tile_size;
		int	ym = y / main->debug.tile_size;
		if (main->map_struct.map[ym][xm] == '1')
			break;
		put_pixel_to_image(main, x, y, 0xF4E700);
		x += step_in_x;
		y += dda_struct->delta_y / dda_struct->delta_x;
		count_steps--;
	}
}

void	dda_case_2(t_main *main, t_dda *dda_struct)
{
	int		count_steps;
	int		step_in_y;
	double	x;
	double	y;

	x = dda_struct->x_1;
	y = dda_struct->y_1;
	if (dda_struct->delta_y > 0)
		step_in_y = 1;
	else
		step_in_y = -1;
	count_steps = fabs(dda_struct->delta_y);
	while (count_steps > 0)
	{
		int	xm = x / main->debug.tile_size;
		int	ym = y / main->debug.tile_size;
		if (main->map_struct.map[ym][xm] == '1')
			break;
		put_pixel_to_image(main, x, y, 0xF4E700);
		y += step_in_y;
		x += dda_struct->delta_x / dda_struct->delta_y;
		count_steps--;
	}
}


t_vec2	digital_differential_analyzer(t_main *main)
{
	t_vec2			wall_hited;
	t_dda_struct	dda_struct;

	dda_struct.origin_x = (int)main->player.x;
	dda_struct.origin_y = (int)main->player.y;
	if (main->ray.dirX == 0)
		dda_struct.delta_x = pow(10, 30);
	else
		dda_struct.delta_x = fabs(1 / main->ray.dirY);
	if (main->ray.dirY == 0)
		dda_struct.delta_y = pow(10, 30);
	else
		dda_struct.delta_y = fabs(1 / main->ray.dirY);
	dda_struct.hit = 0;
	get_step_and_sidedist(main, &dda_struct);
	dda_main_loop(main, &dda_struct);
	wall_hited.x = dda_struct.origin_x;
	wall_hited.y = dda_struct.origin_y;
	return (wall_hited);
}
