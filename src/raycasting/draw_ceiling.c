#include "cub3d.h"

/**
 * @param distance_to_row = horizontal distance from the camera to the floor
 * for the current row. 
 * @remark the ray goes through two points. The camera itself which is at 
 * @param half_screen is 
 */
typedef struct	s_guide
{
	float	rayDirLeft_X;
	float	rayDirLeft_Y;
	float	rayDirRight_X;
	float	rayDirRight_Y;
	int		pixel_distance_down;
	float	pos_z;
	float	distance_to_row;
	float	x_step_right;
	float	y_step_down;
	float	floor_coor_x;
	float	floor_coor_y;
	float	floor_pannel_distance;
	int		floor_grid_x;
	int		floor_grid_y;
	int		color;

}				t_guide;

static void	get_texture_position_floor(t_main *main, int x, int y, t_guide *g)
{
	int	texture_x;
	int	texture_y;
	int	texture_width;
	int	texture_height;

	float _x = g->floor_coor_x + ((float)x * g->x_step_right);
	float _y = g->floor_coor_y + ((float)x * g->y_step_down);
	texture_width = main->texture_bank.floor.width;
	texture_height = main->texture_bank.floor.height;
	texture_x = (int)(texture_width * fabs(_x - (int)_x)) % texture_width;
	texture_y = (int)(texture_height * fabs(_y - (int)_y)) % texture_height;
	g->color = ((int *)main->texture_bank.ceiling.texture.addr)[texture_width * texture_x + texture_y];
	put_pixel_to_image(main, x, y, g->color);
}

/**
 * @remarks the pixel distance is used to know how big or small the proportion of
 * the floor tiles are. 
 */
static void	get_guide_info(t_main *main, t_guide *g, int y)
{
	t_player	*player;

	player = &main->player;
	g->rayDirLeft_X = player->dir_x - player->plane_x;
	g->rayDirLeft_Y = player->dir_y - player->plane_y;
	g->rayDirRight_X = player->dir_x + player->plane_x;
	g->rayDirRight_Y = player->dir_y + player->plane_y;
	g->pixel_distance_down = y - main->cal.half_wh;
	g->pos_z = -0.5 * WIN_HEIGHT;
	g->floor_pannel_distance = g->pos_z / g->pixel_distance_down;
	g->x_step_right = g->floor_pannel_distance * ((g->rayDirRight_X - g->rayDirLeft_X) / WIN_WIDTH); // gives me the incrmeental part of the calculation
	g->y_step_down = g->floor_pannel_distance * ((g->rayDirRight_Y - g->rayDirLeft_Y) / WIN_WIDTH); // scalar calculation
	g->floor_coor_x = player->x + g->floor_pannel_distance * g->rayDirLeft_X;
	g->floor_coor_y = player->y + g->floor_pannel_distance * g->rayDirLeft_Y;
}

void	draw_ceiling(t_main *main, int x, int y)
{
	t_guide	g;

	get_guide_info(main, &g, y);
	get_texture_position_floor(main, x, y, &g);
}