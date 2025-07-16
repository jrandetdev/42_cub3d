#include "cub3d.h"

unsigned int	get_texture_pixel(t_main *main, int texture_x, int coor_y)
{
	long			pixel_offset;
	unsigned int	pixel_color;

	pixel_offset = coor_y * main->wall.no.width + texture_x * main->wall.no.texture.bytespp;
	pixel_color = *(int*)(main->wall.no.texture.addr + pixel_offset);
	return (pixel_color);
}

static void	get_texture_position(t_main *main, t_texture texture, int line_height, int start, int end, int texture_x, int screen_x)
{
	int				tex_pos_y;
	double			step;
	double			texture_pos;
	int				y;
	
	y = start;
	step = 1.0 * texture.height / line_height;
	texture_pos = (start - WIN_HEIGHT / 2 + line_height / 2) * step;
	while (y < end)
	{
		tex_pos_y = (int)texture_pos & (texture.height - 1);
		put_pixel_to_image(main, screen_x, y, get_texture_pixel(main, texture_x, tex_pos_y));
		tex_pos_y += step;
		y++;
	}
}
void	get_line_size(t_main *main, double walldist, int x, unsigned long texture_x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;

	line_height = (int)(WIN_HEIGHT / walldist);
	draw_start = (-line_height / 2) + (WIN_HEIGHT / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (line_height / 2) + (WIN_HEIGHT / 2);
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	get_texture_position(main, main->wall.no, line_height, draw_start, draw_end, texture_x, x);
}
