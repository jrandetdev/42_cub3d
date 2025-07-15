
#include "cub3d.h"

// unsigned int	get_pixel(t_main *main, int x, int y)
// {
// 	long				pixel_offset;
// 	t_myimage			*img;

// 	img = &main->image;
// 	pixel_offset = y * img->size_line + x * img->bytespp;
// 	dst = img->addr + pixel_offset;
	
// }

// unsigned int	get_pixel(t_main *main, int x)
// {
// 	t_myimage	texture;
// 	long		pixel_offset;

// 	texture.addr = mlx_get_data_addr(
// 		main->wall.no.texture_ptr,
// 		texture.bitspp,
// 		texture.size_line,
// 		texture.endian);


// }

unsigned long	get_hit_position(t_main *main, t_dda_struct *dda_struct)
{
	char	texnum;
	double	width_pourcentage;
	double	width_pos_x;
	int		texture_coor_x;

	(void)	texnum;
	texnum = main->map_struct.map[dda_struct->mapY][dda_struct->mapX] - '1';
	if(dda_struct->side == 0)
		width_pos_x = main->player.y + main->ray.dirY * dda_struct->perpwalldist;
	else
		width_pos_x = main->player.x + main->ray.dirX * dda_struct->perpwalldist;
	width_pourcentage = width_pos_x - floor(width_pos_x);
	texture_coor_x = width_pourcentage * main->wall.no.width;
	return (texture_coor_x);
	//printf("texture_coor_x is worth %d, percentage: %f amd teture width: %d\n", texture_coor_x, width_pourcentage, main->wall.no.width);
}
