
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

static bool	check_outside_minimap(t_minimap minimap, t_map map, double x, double y)
{
	int	xm;
	int	ym;
	int	size;

	size = minimap.tile_size;
	xm = (x - minimap.start_px) / size;
	ym = (y - minimap.start_py) / size;
	if (xm < 0 || ym < 0 || xm > (int)map.width || ym > (int)map.height)
		return (false);
	if (map.map[ym][xm] == '1')
		return (false);
	// if (map.map[ym][xm - 1] == '1' && map.map[ym + 1][xm] == '1')
	// 	return (false);
	// if (map.map[ym - 1][xm] == '1' && map.map[ym][xm + 1] == '1')
	// 	return (false);
	return (true);
}

static t_vec2	dda_case_1(t_main *main, t_dda *dda_struct)
{
	int		count_steps;
	int		step_in_x;
	double	x;
	double	y;
	t_vec2	vector;

	step_in_x = 1;
	x = dda_struct->x_1;
	y = dda_struct->y_1;
	count_steps = fabs(dda_struct->delta_x);
	if (dda_struct->delta_x < 0)
		step_in_x = -1;
	while (count_steps > 0)
	{
		if (!check_outside_minimap(main->minimap, main->map_struct, x, y))
			break;
		put_pixel_to_image(main, x, y, 0xF4E700);
		x += step_in_x;
		y += (dda_struct->delta_y / dda_struct->delta_x) * step_in_x;
		count_steps--;
	}
	vector.x = x;
	vector.y = y;
	return(vector);
}

static t_vec2	dda_case_2(t_main *main, t_dda *dda_struct)
{
	int		count_steps;
	int		step_in_y;
	double	x;
	double	y;
	t_vec2	vector;

	step_in_y = 1;
	x = dda_struct->x_1;
	y = dda_struct->y_1;
	if (dda_struct->delta_y < 0)
		step_in_y = -1;
	count_steps = fabs(dda_struct->delta_y);
	while (count_steps > 0)
	{
		if (!check_outside_minimap(main->minimap, main->map_struct, x, y))
			break;
		put_pixel_to_image(main, x, y, 0xF4E700);
		y += step_in_y;
		x += (dda_struct->delta_x / dda_struct->delta_y) * step_in_y;
		count_steps--;
	}
	vector.x = x;
	vector.y = y;
	return(vector);
}

t_vec2	mini_dda(t_main *main, double dst_x, double dst_y)
{
	int	size;
	t_dda	dda_struct;
	t_vec2	vector;

	size = main->minimap.tile_size;
	dda_struct.x_1 = main->minimap.start_px + main->player.x * size;
	dda_struct.y_1 = main->minimap.start_py + main->player.y * size;
	dda_struct.x_2 = main->minimap.start_px + dst_x * size;
	dda_struct.y_2 = main->minimap.start_py + dst_y * size; 
	dda_struct.delta_x = dda_struct.x_2 - dda_struct.x_1;
	dda_struct.delta_y = dda_struct.y_2 - dda_struct.y_1;
	if (fabs(dda_struct.delta_y) <= fabs(dda_struct.delta_x))
		vector = dda_case_1(main, &dda_struct);
	else
		vector = dda_case_2(main, &dda_struct);
	return (vector);
}
