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
	int		total_columns;
	int		floor_grid_x;
	int		floor_grid_y;
	int		color;

}				t_guide;

static void	get_texture_position_floor(t_main *main, int y, t_guide *g)
{
	int	texture_x;
	int	texture_y;
	int	texture_width;
	int	texture_height;
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		g->floor_grid_x = (int)g->floor_coor_x;
		g->floor_grid_y = (int)g->floor_coor_y;
		texture_width = main->texture_bank.floor.width;
		texture_height = main->texture_bank.floor.height;
		texture_x = (int)(texture_width * fabs(g->floor_coor_x - g->floor_grid_x)) % texture_width;
		texture_y = (int)(texture_height * fabs(g->floor_coor_y - g->floor_grid_y)) % texture_height;
		// if (texture_x < 0)
		// 	texture_x += texture_width;
		// if (texture_y < 0)
		// 	texture_y += texture_width;
		g->floor_coor_x += g->x_step_right;
		g->floor_coor_y += g->y_step_down;
		g->color = ((int *)main->texture_bank.floor.texture.addr)[texture_width * texture_x + texture_y];
		put_pixel_to_image(main, x, y, g->color);
		x++;
	}	
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
	g->pos_z = 0.5 * WIN_HEIGHT;
	g->total_columns = WIN_WIDTH;
	g->floor_pannel_distance = g->pos_z / g->pixel_distance_down;
	g->x_step_right = g->floor_pannel_distance * ((g->rayDirRight_X - g->rayDirLeft_X) / g->total_columns); // gives me the incrmeental part of the calculation
	g->y_step_down = g->floor_pannel_distance * ((g->rayDirRight_Y - g->rayDirLeft_Y) / g->total_columns); // scalar calculation
	g->floor_coor_x = player->x + g->floor_pannel_distance * g->rayDirLeft_X;
	g->floor_coor_y = player->y + g->floor_pannel_distance * g->rayDirLeft_Y;
}

void	draw_floor(t_main *main)
{
	t_guide	g;
	int		y;

	y = main->cal.half_wh;
	while (y < WIN_HEIGHT)
	{
		get_guide_info(main, &g, y);
		get_texture_position_floor(main, y, &g);
		y++;
	}
}
