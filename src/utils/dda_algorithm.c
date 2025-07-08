
#include "cub3d.h"

typedef struct s_dda_struct
{
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		delta_x;
	double		delta_y;
	int			step_x;
	int			step_y;
	double		perpwalldist;
	bool		hit;
	int			side;
}	t_dda_struct;

static void	get_wall_dist(t_dda_struct *dda_struct)
{
	
	if (dda_struct->side == 0)
		dda_struct->perpwalldist = (dda_struct->sideDistX - dda_struct->delta_x);
	else
		dda_struct->perpwalldist = (dda_struct->sideDistY - dda_struct->delta_y);
}

/**
 * @param sideDistX et Y sont un vecteur que l'on multiolie avec le scalairesdu vecteur !
 * @brief On augmente le vecteur SideDistX ou SideDistY selon l'angle du vecteur
 */
static void dda_main_loop(t_main *main, t_dda_struct *dda_struct)
{
	// t_vec2	vector;
	while (dda_struct->hit == 0) // continue tant que mur n'est pas hit
	{
		if (dda_struct->sideDistX < dda_struct->sideDistY)
		{
			dda_struct->sideDistX += dda_struct->delta_x;
			dda_struct->mapX += dda_struct->step_x;
			dda_struct->side = 0;
		}
		else
		{
			dda_struct->sideDistY += dda_struct->delta_y;
			dda_struct->mapY += dda_struct->step_y;
			dda_struct->side = 1;
		}
		if (main->map_struct.map[(int)dda_struct->mapY][(int)dda_struct->mapX] != '0')
			dda_struct->hit = 1;
	}
}

static void	get_step_and_sidedist(t_main *main, t_dda_struct *dda_struct)
{
	if (main->ray.dirX < 0) // si le rayon est dans la partie gauche de l'ecrann, step x sera -1
	{
		dda_struct->step_x = -1;
		dda_struct->sideDistX = (main->player.x - dda_struct->mapX) * dda_struct->delta_x;
	}
	else
	{
		dda_struct->step_x = 1;
		dda_struct->sideDistX = (dda_struct->mapX + 1.0 - main->player.x) * dda_struct->delta_x;
	}
	if (main->ray.dirY < 0)
	{
		dda_struct->step_y = -1;
		dda_struct->sideDistY = (main->player.y - dda_struct->mapY) * dda_struct->delta_y;
	}
	else
	{
		dda_struct->step_y = 1;
		dda_struct->sideDistY =(dda_struct->mapY + 1.0 - main->player.y) * dda_struct->delta_y;
	}
}


double	digital_differential_analyzer(t_main *main)
{
	t_dda_struct	dda_struct;

	ft_bzero(&dda_struct, sizeof(t_dda_struct));
	dda_struct.mapX = main->player.x;
	dda_struct.mapY = main->player.y;
	if (main->ray.dirX == 0)
		dda_struct.delta_x = pow(10, 30);
	else
		dda_struct.delta_x = fabs(1 / main->ray.dirX); // pre calculer de combien on va monter en X delta
	if (main->ray.dirY == 0)
		dda_struct.delta_y = pow(10, 30);
	else
		dda_struct.delta_y = fabs(1 / main->ray.dirY);
	dda_struct.hit = 0;
	get_step_and_sidedist(main, &dda_struct);
	dda_main_loop(main, &dda_struct);
	get_wall_dist(&dda_struct);
	return (dda_struct.perpwalldist);
}
