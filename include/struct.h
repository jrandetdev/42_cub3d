
#ifndef STRUCT_H
#define STRUCT_H

#include "bonus_struct.h"

/*---------------------------------- ENUM ------------------------------------*/
enum start_angle
{
	N = 0,
	E = 90,
	S = 180,
	W = 270,
};

/*---------------------------------- UNION -----------------------------------*/
typedef union
{
	int value;
	struct
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	};
}	t_colour;

/*--------------------------------- STRUCT -----------------------------------*/

typedef struct	s_vec2
{
	double	x;
	double	y;
}				t_vec2;
typedef struct 	s_ray
{
	double	dirX;
	double	dirY;
}				t_ray;

typedef struct s_debug
{
	bool	debug;
	int		last_keycode;
}	t_debug;

typedef struct s_map
{
	char			**map;
	unsigned int	height;
	unsigned int	width;

}				t_map;

typedef struct s_minimap
{
	int	start_px;
	int	start_py;
	int	tile_size;
	int	map_size_x;
	int	map_size_y;
}	t_minimap;

typedef struct s_parsing
{
	int		player;
	int		patern;
	char	**map;
	int		map_width;
	int		map_height;
}	t_parsing;


typedef struct s_params
{
	int		start;
	int		screen_x;
	int		screen_y;
	int		draw_end;
	int		texture_x;
	int		draw_start;
	int		wall_height;
	double	step;
}				t_params;

typedef struct	s_cal
{
	int		half_wh;
	int		half_ww;
	double	pre_fov;
	double	cf_ray_dirx_left;
	double	cf_ray_diry_left;
	double	cf_ray_dirx_right;
	double	cf_ray_diry_right;
	double	cf_pre_step_right;
	double	cf_pre_step_down;
}				t_cal;

typedef struct	s_myimage
{
	void	*data_img;
	void	*addr;
	int		bitspp;
	int		bytespp;
	int		size_line;
	int		total_bytes;
	int		pixels_per_line;
	int		endian;
}				t_myimage;

typedef struct	s_texture
{
	void		*texture_ptr;
	int			width;
	int			height;
	t_myimage	texture;
}				t_texture;

typedef struct	s_player
{
	double	x;
	double	y;
	double	angle;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	camera_y;
	char	*cardinal_direction;
}				t_player;

typedef struct	s_texture_bank
{
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
	t_texture		door;
	t_texture		floor;
	t_texture		ceiling;
}				t_texture_bank;

typedef struct s_mini_dda_struct
{
	double	m;
	double	x_1;
	double	y_1;
	double	x_2;
	double	y_2;
	double	delta_x;
	double	delta_y;
}	t_mini_dda_struct;

typedef struct s_dda_struct
{
	int			mapX;
	int			mapY;
	int			hit;
	int			side;
	int			step_x;
	int			step_y;
	double		delta_x;
	double		delta_y;
	double		ray_dirx;
	double		ray_diry;
	double		camera_x;
	double		sideDistX;
	double		sideDistY;
	double		perpwalldist;
	double		door_hit_percentage;
}	t_dda_struct;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	g;
	int	m;
	int	e;
	int	p;
	int	up;
	int escp;
	int	down;
	int	left;
	int	right;
	int	enter;
	int	shift;
}	t_keys;

typedef struct	s_main
{
	int					menu;
	int					rotation;
	int					game_start;
	void				*mlx_ptr;
	void				*mlx_win;
	char				**id_and_info;
	char				**file_content;
	t_cal				cal;
	t_ray				ray;
	t_door				door;
	t_keys				keys;
	t_bonus				bonus;
	t_debug				debug;
	t_mouse				mouse;
	t_myimage			image;
	t_menu_param		param;
	t_player			player;
	t_minimap			minimap;
	t_mini_dda_struct	mini_dda_struct;
	t_colour			c_colour;
	t_colour			f_colour;
	t_map				map_struct;
	t_texture_bank		texture_bank;
}				t_main;

#endif