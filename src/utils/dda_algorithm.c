
#include "cub3d.h"
#include <math.h>

// typedef struct s_dda
// {
// 	double	m;
// 	double	x_1;
// 	double	y_1;
// 	double	x_2;
// 	double	y_2;
// 	double	delta_x;
// 	double	delta_y;
// }	t_dda;

// void	dda_case_1(t_main *main, t_dda *dda_struct)
// {
// 	int	step;
// 	int	x;
// 	int	y;

// 	x = dda_struct->x_1;
// 	y = dda_struct->y_1;
// 	step = dda_struct->delta_x;
// 	while (step > 0)
// 	{
// 		put_pixel_to_image(main, x, y, 0xF4E700);
// 		x += 1;
// 		y += dda_struct->delta_y / dda_struct->delta_x;
// 		step--;
// 	}
// }

// void	dda_case_2(t_dda *dda_struct)
// {
// 	int	step;
// 	int	x;
// 	int	y;

// 	x = dda_struct->x_1;
// 	y = dda_struct->y_1;
// 	step = dda_struct->delta_y;
// 	while (step > 0)
// 	{
// 		y += 1;
// 		step--;
// 	}
// }

// void	digital_differential_analyzer(t_main *main, double dst_x, double dst_y)
// {
// 	t_dda	dda_struct;

// 	dda_struct.x_1 = main->player.x;
// 	dda_struct.y_1 = main->player.y;
// 	dda_struct.x_2 = dst_x;
// 	dda_struct.y_2 = dst_y;
// 	dda_struct.delta_x = dda_struct.x_2 - dda_struct.x_1;
// 	dda_struct.delta_y = dda_struct.y_2 - dda_struct.y_1;
// 	if (dda_struct.delta_y <= dda_struct.delta_x)
// 		dda_case_1(&dda_struct);
// 	else
// 		dda_case_2(&dda_struct);
// }

// void	dda_algo(t_main *main, double dst_x, double dst_y)
// {
// 	int		x;
// 	int		y;
// 	//double	m; //angle
// 	double	dx;
// 	double	dy;

// 	//m = x2 - x1;
// 	dx = (dst_x - main->player.x) * main->debug.tile_size;
// 	dy = (dst_y - main->player.y) * main->debug.tile_size;
// 	x = main->player.x * main->debug.tile_size;
// 	y = main->player.y * main->debug.tile_size;
// 	for (int i = 0; i < fmax(dx, dy); i++)
// 	{
// 		x += fmax(dx, dy) / dx;
// 		y += fmax(dx, dy) / dy;
// 		put_pixel_to_image(main, x, y, 0xF4E700); 
// 	}
// }