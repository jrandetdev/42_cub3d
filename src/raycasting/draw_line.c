#include "cub3d.h"

static void	draw_wall(t_main *main, int start, int end, int x)
{
	int	y;

	y = start;
	//
	while (y <= end)
	{

		put_pixel_to_image(main, x, y, 0x000000);
		y++;
	}
}


void	draw_line(t_main *main, double walldist, int x)
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
	draw_wall(main, draw_start, draw_end, x);
}
