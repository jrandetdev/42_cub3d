
#include "cub3d.h"

static double get_texture_offset(t_main *main, t_myimage*texture, int x)
{
	long				texture_offset;

	texture_offset = main->wall_hit.x * texture->size_line;
	// if (texture_offset > texture->total_bytes)
	// {
	// 	exit_cub3d(main, "Coordinates are outside of map capacity.");
	// 	return(0);
	// }
	if (x == WIN_WIDTH / 2)
		printf("percentage of the texture in width: %f\n", main->wall_hit.x);
	return (texture_offset);
}

void get_texture_pixel(t_main *main, int x)
{
	t_myimage	*texture;

	texture = &main->wall_hit.texture;
	
	(void) texture->endian;
	(void) texture->bitspp;
	//main->wall_hit.x -= trunc(main->wall_hit.x);
	texture->addr = mlx_get_data_addr(
		&main->wall.no,
		&texture->bitspp,
		&texture->size_line,
		&texture->endian);
	if (!texture->addr)
		return (exit_cub3d(main, "Texture get data addr failed."));
	texture->bytespp = texture->bitspp / 8;
	texture->pixels_per_line = texture->size_line / texture->bytespp;
	if (get_texture_offset(main, texture, x) == 0)
		return ;
}