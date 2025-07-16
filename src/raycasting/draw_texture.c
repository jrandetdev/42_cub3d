#include "cub3d.h"

static void	get_texture_position(t_main *main, t_texture texture, int wall_height, int start, int end, int texture_x, int screen_x)
{
	int				tex_pos_y;
	double			step;
	double			texture_pos;
	int				screen_y;
	int				color;
	
	screen_y = start;
	step = (double)texture.height / wall_height;
	texture_pos = (start - WIN_HEIGHT / 2 + wall_height / 2) * step;
	while (screen_y < end)
	{
		tex_pos_y = (int)texture_pos & (texture.height - 1);
		color = ((int *)main->wall.no.texture.addr)[main->wall.no.width * tex_pos_y + texture_x];
		put_pixel_to_image(main, screen_x, screen_y, color);
		texture_pos += step;
		screen_y++;
	}
}

static	int	get_hit_position(t_main *main, t_dda_struct *dda_struct)
{
	double	width_pourcentage;
	double	width_pos_x;
	int		texture_coor_x;

	if(dda_struct->side == 0)
		width_pos_x = main->player.y + main->ray.dirY * dda_struct->perpwalldist;
	else
		width_pos_x = main->player.x + main->ray.dirX * dda_struct->perpwalldist;
	width_pourcentage = width_pos_x - floor(width_pos_x);
	texture_coor_x = (width_pourcentage * main->wall.no.width);
	if (dda_struct->side == 0 && main->ray.dirX > 0)
		texture_coor_x = main->wall.no.width - texture_coor_x - 1;
	if (dda_struct->side == 1 && main->ray.dirY < 0)
		texture_coor_x = main->wall.no.width - texture_coor_x - 1;
	return (texture_coor_x);
}

void	draw_texture(t_main *main, t_dda_struct *dda_struct, int x)
{
	int			texture_coor_x;
	int			wall_height;
	int			draw_start;
	int			draw_end;

	texture_coor_x = get_hit_position(main, dda_struct);
	wall_height = (int)(WIN_HEIGHT / dda_struct->perpwalldist);
	draw_start = (-wall_height / 2) + (WIN_HEIGHT / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (wall_height / 2) + (WIN_HEIGHT / 2);
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	get_texture_position(main, main->wall.no, wall_height, draw_start, draw_end, texture_coor_x, x);
}