
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

static void	dda_case_1(t_main *main, t_dda *dda_struct)
{
	int		count_steps;
	int		step_in_x;
	double	x;
	double	y;

	step_in_x = 1;
	x = dda_struct->x_1;
	y = dda_struct->y_1;
	count_steps = fabs(dda_struct->delta_x);
	if (dda_struct->delta_x < 0)
		step_in_x = -1;
	while (count_steps > 0)
	{
		int	xm = (x - main->minimap.start_px) / main->minimap.tile_size;
		int	ym = (y - main->minimap.start_py) / main->minimap.tile_size;
		if (main->map_struct.map[ym][xm] == '1')
			break;
		put_pixel_to_image(main, x, y, 0xF4E700);
		x += step_in_x;
		y += (dda_struct->delta_y / dda_struct->delta_x) * step_in_x;
		count_steps--;
	}
}

static void	dda_case_2(t_main *main, t_dda *dda_struct)
{
	int		count_steps;
	int		step_in_y;
	double	x;
	double	y;

	step_in_y = 1;
	x = dda_struct->x_1;
	y = dda_struct->y_1;
	if (dda_struct->delta_y < 0)
		step_in_y = -1;
	count_steps = fabs(dda_struct->delta_y);
	while (count_steps > 0)
	{
		int	xm = (x - main->minimap.start_px) / main->minimap.tile_size;
		int	ym = (y - main->minimap.start_py) / main->minimap.tile_size;
		if (main->map_struct.map[ym][xm] == '1')
			break;
		put_pixel_to_image(main, x, y, 0xF4E700);
		y += step_in_y;
		x += (dda_struct->delta_x / dda_struct->delta_y) * step_in_y;
		count_steps--;
	}
}

void	mini_dda(t_main *main, double dst_x, double dst_y)
{
	int	size;
	t_dda	dda_struct;

	size = main->minimap.tile_size;
	dda_struct.x_1 = main->minimap.start_px + main->player.x * size;
	dda_struct.y_1 = main->minimap.start_py + main->player.y * size;
	dda_struct.x_2 = main->minimap.start_px + dst_x * size;
	dda_struct.y_2 = main->minimap.start_py + dst_y * size; 
	dda_struct.delta_x = dda_struct.x_2 - dda_struct.x_1;
	dda_struct.delta_y = dda_struct.y_2 - dda_struct.y_1;
	if (fabs(dda_struct.delta_y) <= fabs(dda_struct.delta_x))
		dda_case_1(main, &dda_struct);
	else
		dda_case_2(main, &dda_struct);
}
