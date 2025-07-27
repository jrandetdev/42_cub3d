
#ifndef STRUCT_H
#define STRUCT_H

#include "cub3d.h"

typedef struct	s_main t_main;
typedef struct	s_texture t_texture;

// BONUS //

enum MENU
{
	NO_MENU = 0,
	MAIN_MENU = 1,
	PAUSE_MENU = 2,
	OPTION_MENU = 3,
	RESOLUTION_OPTION = 4,
	FOV_OPTION = 5,
	DEBUG_MENU = 6,
};

enum MAIN_MENU
{
	PLAY = 0,
	OPTION = 1,
	DEBUG = 2,
	QUIT = 3,
};

typedef struct	s_mouse
{
	double	x;
	double	dist;
}				t_mouse;

typedef struct	s_bonus
{
	struct timeval	last_sec;
	unsigned int	fps;
}				t_bonus;

typedef	struct	s_menu_param
{
	int	fov;
	int	sensitivity;
	int	show_minimap;
	int	show_minimap_grid;
}
				t_menu_param;

typedef struct	s_menu_struct
{
	int	y;
	int	idx;
	int	selection;
	int	menu_size;
}				t_menu_struct;

// MANDATORY PART //

enum SYSTEM
{
	LINUX = 1,
	MACOS = 2,
};

typedef struct	s_cal
{
	int		half_wh;
	int		half_ww;
	double	pre_fov;
}				t_cal;

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
	int			hit;
	int			side;
}	t_dda_struct;

typedef struct 	s_ray
{
	double	dirX;
	double	dirY;
}				t_ray;

typedef struct s_minimap
{
	int	start_px;
	int	start_py;
	int	tile_size;
	int	map_size_x;
	int	map_size_y;
}	t_minimap;

enum start_angle
{
	N = 0,
	E = 90,
	S = 180,
	W = 270,
};

typedef struct s_parsing
{
	int		player;
	int		patern;
	char	**map;
	int		map_width;
	int		map_height;
}	t_parsing;

typedef struct s_debug
{
	bool	debug;
	int		grid_separator;
	int		tile_size;
	int		last_keycode;
	double	last_vector_size;
}	t_debug;

typedef struct	s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	camera_y;
	double	angle;
	char	*cardinal_direction;
}				t_player;

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

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct	s_myimage
{
	void	*data_img;
	void	*addr;
	int		size_line;
	int		bitspp;
	int		bytespp;
	int		total_bytes;
	int		pixels_per_line;
	int		endian;
}	t_myimage;


typedef struct	s_texture
{
	void		*texture_ptr;
	int			width;
	int			height;
	t_myimage	texture;
}				t_texture;

typedef struct	s_animation
{
	t_texture	door[6];
}				t_animation;

typedef union
{
	int	value;
	struct
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	};
}	t_colour;

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

typedef struct s_map
{
	char			**map;
	unsigned int	height;
	unsigned int	width;

}				t_map;

typedef struct	s_main
{
	int				os;
	int				rotation;
	int				menu;
	int				animation_playing;
	int				game_start;
	void			*mlx_ptr;
	void			*mlx_win;
	char			**file_content;
	char			**id_and_info;
	t_map			map_struct;
	t_debug			debug;
	t_player		player;
	t_ray			ray;
	t_keys			keys;
	t_texture_bank	texture_bank;
	t_animation		animation;
	t_colour		c_colour;
	t_colour		f_colour;
	t_minimap		minimap;
	t_myimage		image;
	t_mouse			mouse;
	t_bonus			bonus;
	t_cal			cal;
	t_menu_param	param;
}				t_main;

#endif