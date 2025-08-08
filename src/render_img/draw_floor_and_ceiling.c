/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:38:19 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/08 11:49:01 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @param distance_to_row = horizontal distance from the camera to the floor
 * for the current row. 
 * @remark the ray goes through two points. The camera itself which is at 
 * @param half_screen is 
*/
static void	get_texture_position_floor(t_main *main, int x, int y, t_guide *g)
{
	int			texture_width;
	int			texture_height;
	float		_y;
	float		_x;
	t_texture	*texture;

	if (g->pos_z < 0)
		texture = &main->texture_bank.ceiling;
	else
		texture = &main->texture_bank.floor;
	_x = g->floor_coor_x + ((float)x * g->x_step_right);
	_y = g->floor_coor_y + ((float)x * g->y_step_down);
	texture_width = texture->width;
	texture_height = texture->height;
	g->texture_x = (int)(texture_width * fabs(_x - (int)_x))
		% texture_width;
	g->texture_y = (int)(texture_height * fabs(_y - (int)_y))
		% texture_height;
	g->color = ((int *)texture->texture.addr)
	[texture_width * g->texture_x + g->texture_y];
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
	g->pixel_distance_down = y - main->cal.half_wh;
	g->floor_pannel_distance = g->pos_z / g->pixel_distance_down;
	g->x_step_right = g->floor_pannel_distance * main->cal.cf_pre_step_right;
	g->y_step_down = g->floor_pannel_distance * main->cal.cf_pre_step_down;
	g->floor_coor_x = player->x + g->floor_pannel_distance
		* main->cal.cf_ray_dirx_left;
	g->floor_coor_y = player->y + g->floor_pannel_distance
		* main->cal.cf_ray_diry_left;
}

void	draw_floor_and_ceiling(t_main *main, int x, int y, float z)
{
	t_guide	g;

	g.pos_z = z * WIN_HEIGHT;
	get_guide_info(main, &g, y);
	get_texture_position_floor(main, x, y, &g);
}
