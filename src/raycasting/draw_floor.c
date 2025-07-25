// #include "cub3d.h"

// /**
//  * @param distance_to_row = horizontal distance from the camera to the floor
//  * for the current row. 
//  * @remark the ray goes through two points. The camera itself which is at 
//  * @param half_screen is 
//  */
// typedef struct	s_guide
// {
// 	float	rayDirLeft_X;
// 	float	rayDirLeft_Y;
// 	float	rayDirRight_X;
// 	float	rayDirRight_Y;
// 	int		pixel_distance_down;
// 	float	pos_z;
// 	float	distance_to_row;
// 	float	x_step_right;
// 	float	y_step_down;
// 	float	floor_coor_x;
// 	float	floor_coor_y;
// 	float	floor_pannel_distance;
// 	int		total_columns;
// 	int		floor_grid_x;
// 	int		floor_grid_y;

// }				t_guide;

// static void	get_texture_position(t_main *main, t_guide *g)
// {

// }

// /**
//  * @remarks the pixel distance is used to know how big or small the proportion of
//  * the floor tiles are. 
//  */
// static void	get_guide_info(t_main *main, t_guide *g, int y)
// {
// 	t_player	*player;

// 	g->rayDirLeft_X = player->dir_x - player->plane_x;
// 	g->rayDirLeft_Y = player->dir_y - player->plane_y;
// 	g->rayDirRight_X = player->dir_x + player->plane_x;
// 	g->rayDirRight_Y = player->dir_y + player->plane_y;
// 	g->pixel_distance_down = y - WIN_HEIGHT / 2;
// 	g->pos_z = 0.5 * WIN_HEIGHT;
// 	g->total_columns = WIN_WIDTH;
// 	g->floor_pannel_distance = g->pos_z / g->pixel_distance_down;
// 	g->x_step_right = g->floor_pannel_distance * ((g->rayDirRight_X - g->rayDirLeft_X) / g->total_columns); // gives me the incrmeental part of the calculation
// 	g->y_step_down = g->floor_pannel_distance * ((g->rayDirRight_Y - g->rayDirLeft_Y) / g->total_columns); // scalar calculation
// 	g->floor_coor_x = player->x + g->floor_pannel_distance * g->rayDirLeft_X;
// 	g->floor_coor_y = player->y + g->floor_pannel_distance * g->rayDirRight_Y;
// }

// void	draw_floor(t_main *main)
// {
// 	t_guide	g;
// 	int		y;
// 	int		x;
// 	int		tx;
// 	int		ty;

// 	y = 0;
// 	while (y < WIN_HEIGHT)
// 	{
// 		get_guide_info(main, &g, y);
// 		x = 0;
// 		while (x < WIN_WIDTH)
// 		{
// 			g.floor_grid_x = (int)g.floor_coor_x;
// 			g.floor_grid_y = (int)g.floor_coor_y;

// 			tx = (int)(main->texture_bank.floor.width) * (g.floor_coor_x - g.floor_grid_x) % 
// 		}
// 		y++;
// 	}

// }