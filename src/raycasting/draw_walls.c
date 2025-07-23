/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:29:29 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/23 15:10:39 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_params
{
	int		wall_height;
	int		start;
	int		draw_start;
	int		draw_end;
	int		texture_x;
	int		screen_x;
	int		screen_y;
	double	step;
}				t_params;

static void	get_texture_position(t_main *main, t_texture t, t_params *p)
{
	int				tex_pos_y;
	double			step;
	double			texture_pos;
	int				screen_y;
	int				color;

	screen_y = p->draw_start;
	step = (double)t.height / p->wall_height;
	texture_pos = (p->draw_start - WIN_HEIGHT / 2 + p->wall_height / 2) * step;
	while (screen_y < p->draw_end)
	{
		tex_pos_y = (int)texture_pos & (t.height - 1);
		color = ((int *)t.texture.addr)[t.width * tex_pos_y + p->texture_x];
		put_pixel_to_image(main, p->screen_x, screen_y, color);
		texture_pos += step;
		screen_y++;
	}
}

static	int	get_hit_position(t_main *main, t_dda_struct *dda_s,
	t_texture texture, t_params *p)
{
	double	width_pourcentage;
	double	width_pos_x;

	if (dda_s->side == 0)
		width_pos_x = main->player.y + main->ray.dirY * dda_s->perpwalldist;
	else
		width_pos_x = main->player.x + main->ray.dirX * dda_s->perpwalldist;
	width_pourcentage = width_pos_x - floor(width_pos_x);
	p->texture_x = (width_pourcentage * texture.width);
	if (dda_s->side == 0 && main->ray.dirX > 0)
		p->texture_x = texture.width - p->texture_x - 1;
	if (dda_s->side == 1 && main->ray.dirY < 0)
		p->texture_x = texture.width - p->texture_x - 1;
	return (p->texture_x);
}

void	draw_texture(t_main *main, t_dda_struct *dda_struct, int x,
	t_texture texture)
{
	t_params	params;

	params.screen_x = x;
	params.texture_x = get_hit_position(main, dda_struct, texture, &params);
	params.wall_height = (int)(WIN_HEIGHT / dda_struct->perpwalldist);
	params.draw_start = (WIN_HEIGHT / 2) - (params.wall_height / 2);
	if (params.draw_start < 0)
		params.draw_start = 0;
	params.draw_end = (params.wall_height / 2) + (WIN_HEIGHT / 2);
	if (params.draw_end >= WIN_HEIGHT)
		params.draw_end = WIN_HEIGHT - 1;
	get_texture_position(main, texture, &params);
}

t_texture	get_corresp_texture(t_main *main, t_dda_struct *dda_struct)
{
	t_texture	texture;

	if (dda_struct->hit == 2)
	{
		texture = main->wall.door;
		return (texture);
	}
	if (dda_struct->side == 0)
	{
		if (main->ray.dirX > 0)
			texture = main->wall.ea;
		else
			texture = main->wall.we;
	}
	else
	{
		if (main->ray.dirY < 0)
			texture = main->wall.no;
		else
			texture = main->wall.so;
	}
	return (texture);
}
