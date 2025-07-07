
#include "cub3d.h"

typedef struct s_dda_struct
{
	double		origin_x;
	double		origin_y;
	double		sideDistX;
	double		sideDistY;
	double		delta_x;
	double		delta_y;
	int			step_x;
	int			step_y;
	double		perpwalldist;
	bool		hit;
	int			side;
}				t_dda_struct;

t_vec2	dda_main_loop(t_main *main, t_dda_struct *dda_struct)
{
	t_vec2	vector;

	while (dda_struct->hit == 0)
	{
		if (dda_struct->sideDistX < dda_struct->sideDistY)
		{
			dda_struct->sideDistX += dda_struct->delta_x;
			dda_struct->origin_x += dda_struct->step_x;
			dda_struct->side = 0;
		}
		else
		{
			dda_struct->sideDistY += dda_struct->delta_y;
			dda_struct->origin_y += dda_struct->step_y;
			dda_struct->side = 1;
		}
		if (main->map_struct.map[(int)dda_struct->origin_y][(int)dda_struct->origin_x] != '0')
			dda_struct->hit = 1;
	}
	vector.x = dda_struct->origin_x;
	vector.y = dda_struct->origin_y;
	return (vector);
}

void	get_step_and_sidedist(t_main *main, t_dda_struct *dda_struct)
{
	if (main->ray.dirX < 0)
	{
		dda_struct->step_x = -1;
		dda_struct->sideDistX = (main->player.x - dda_struct->origin_x) * dda_struct->delta_x;
	}
	else
	{
		dda_struct->step_x = 1;
		dda_struct->sideDistX = (dda_struct->origin_x + 1.0 - main->player.x) * dda_struct->delta_x;
	}
	if (main->ray.dirY < 0)
	{
		dda_struct->step_y = -1;
		dda_struct->sideDistY = (main->player.y - dda_struct->origin_y) * dda_struct->delta_y;
	}
	else
	{
		dda_struct->step_y = 1;
		dda_struct->sideDistY =(dda_struct->origin_y + 1.0 - main->player.y) * dda_struct->delta_y;
	}
}


t_vec2	digital_differential_analyzer(t_main *main)
{
	t_dda_struct	dda_struct;

	dda_struct.origin_x = main->player.x;
	dda_struct.origin_y = main->player.y;
	if (main->ray.dirX == 0)
		dda_struct.delta_x = pow(10, 30);
	else
		dda_struct.delta_x = fabs(1 / main->ray.dirY);
	if (main->ray.dirY == 0)
		dda_struct.delta_y = pow(10, 30);
	else
		dda_struct.delta_y = fabs(1 / main->ray.dirY);
	dda_struct.hit = 0;
	printf("BEFORE X %d Y %d\n", dda_struct.origin_x, dda_struct.origin_y);
	get_step_and_sidedist(main, &dda_struct);
	return(dda_main_loop(main, &dda_struct));

}
