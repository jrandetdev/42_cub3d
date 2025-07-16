
#include "cub3d.h"

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
	if (dda_struct->side == 0 && main->ray.dirX > 0)
		texture_coor_x = main->wall.no.width - texture_coor_x - 1;
	if (dda_struct->side == 1 && main->ray.dirY < 0)
		texture_coor_x = main->wall.no.width - texture_coor_x - 1;
	return (texture_coor_x);
}
