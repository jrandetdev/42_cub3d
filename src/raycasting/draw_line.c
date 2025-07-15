#include "cub3d.h"

unsigned int	get_texture_pixel(t_main *main, int coor_x, int y)
{
	long			pixel_offset;
	unsigned int	pixel_color;

	// texture.data_img = main->wall.no.texture_ptr;
	// texture.addr = mlx_get_data_addr(
	// 	main->wall.no.texture_ptr,
	// 	&texture.bitspp,
	// 	&texture.size_line,
	// 	&texture.endian);
	// if (!texture.addr)
	// 	exit_cub3d(main, "Mlx_get_data_addr failed.");
	// texture.bytespp = texture.bitspp / 8;
	// texture.pixels_per_line = texture.size_line / texture.bytespp;
	// texture.total_bytes = texture.size_line * main->wall.no.height;
	pixel_offset = y * main->wall.no.width + coor_x * main->wall.no.texture.bytespp;
	pixel_color = *(int*)(main->wall.no.texture.addr + pixel_offset);
	return (pixel_color);
}

static void	draw_wall(t_main *main, int start, int end, int x, unsigned long coor_x)
{
	int	y;

	y = start;
	//
	while (y <= end)
	{
		put_pixel_to_image(main, x, y, get_texture_pixel(main, coor_x, y - start));
		y++;
	}
}

void	draw_line(t_main *main, double walldist, int x, unsigned long coor_x)
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
	draw_wall(main, draw_start, draw_end, x, coor_x);
}
