/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:29:29 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/07 10:09:00 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_texture_position(t_main *main, t_texture t, t_params *p)
{
	int				y = 0;
	int				tex_pos_y;
	double			step;
	double			texture_pos;
	int				screen_y;
	int				color;

	screen_y = p->draw_start;
	step = (double)t.height / p->wall_height;
	texture_pos = (p->draw_start - main->cal.half_wh + p->wall_height / 2) * step;
	while (main->is_celling_texture && y < screen_y)
		draw_floor_and_ceiling(main, p->screen_x, y++, -0.5);
	while (screen_y < p->draw_end)
	{
		tex_pos_y = (int)texture_pos & (t.height - 1);
		color = ((int *)t.texture.addr)[t.width * tex_pos_y + p->texture_x];
		put_pixel_to_image(main, p->screen_x, screen_y, color);
		texture_pos += step;
		screen_y++;
	}
	while (main->is_floor_texture && screen_y < WIN_HEIGHT)
	{
		draw_floor_and_ceiling(main, p->screen_x, screen_y++, 0.5);
	}
}

static	int	get_hit_position(t_main *main, t_dda_struct *dda_s,
	t_texture texture, t_params *p)
{
	double	width_pourcentage;
	double	width_pos_x;

	if (dda_s->side == 0)
		width_pos_x = main->player.y + dda_s->ray_diry * dda_s->perpwalldist;
	else
		width_pos_x = main->player.x + dda_s->ray_dirx * dda_s->perpwalldist;
	width_pourcentage = width_pos_x - floor(width_pos_x);
	if (dda_s->hit == 3)
	{
		if (dda_s->door_hit_percentage <= 0.5)
			p->texture_x = ((width_pourcentage + main->door.opening_pourcent / 2) * texture.width);
		if (dda_s->door_hit_percentage > 0.5)
			p->texture_x = ((width_pourcentage - main->door.opening_pourcent / 2) * texture.width);
	}
	else
		p->texture_x = (width_pourcentage * texture.width);
	if (dda_s->side == 0 && dda_s->ray_dirx > 0)
		p->texture_x = texture.width - p->texture_x - 1;
	if (dda_s->side == 1 && dda_s->ray_diry < 0)
		p->texture_x = texture.width - p->texture_x - 1;
	return (p->texture_x);
}

void	draw_texture(t_main *main, t_dda_struct *dda_struct, int x,
	t_texture texture)
{
	t_params	params;

	ft_bzero(&params, sizeof(t_params));
	params.screen_x = x;
	params.texture_x = get_hit_position(main, dda_struct, texture, &params);
	params.wall_height = (int)(WIN_HEIGHT / dda_struct->perpwalldist);
	params.draw_start = (main->cal.half_wh) - (params.wall_height / 2);
	if (params.draw_start < 0)
		params.draw_start = 0;
	params.draw_end = (params.wall_height / 2) + (main->cal.half_wh);
	if (params.draw_end >= WIN_HEIGHT)
		params.draw_end = WIN_HEIGHT - 1;
	get_texture_position(main, texture, &params);
}

t_texture	get_corresp_texture(t_main *main, t_dda_struct *dda_struct)
{
	t_texture	texture;

	if (dda_struct->hit == 2 || dda_struct->hit == 3)
	{
		texture = main->texture_bank.door;
		return (texture);
	}
	if (dda_struct->side == 0)
	{
		if (dda_struct->ray_dirx > 0)
			texture = main->texture_bank.ea;
		else
			texture = main->texture_bank.we;
	}
	else
	{
		if (dda_struct->ray_diry < 0)
			texture = main->texture_bank.no;
		else
			texture = main->texture_bank.so;
	}
	return (texture);
}
