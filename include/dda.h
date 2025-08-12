#ifndef DDA_H
# define DDA_H

typedef struct s_dda
{
	int			mapx;
	int			mapy;
	int			hit;
	int			side;
	int			step_x;
	int			step_y;
	float		delta_x;
	float		delta_y;
	float		ray_dirx;
	float		ray_diry;
	float		camera_x;
	float		sidedistx;
	float		sidedisty;
	float		perpwalldist;
	float		door_hit_percentage;
}				t_dda;

typedef struct s_mini_dda
{
	float	m;
	float	x_1;
	float	y_1;
	float	x_2;
	float	y_2;
	float	delta_x;
	float	delta_y;
}			t_mini_dda;

#endif