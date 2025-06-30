
#ifndef STRUCT_H
#define STRUCT_H

#include "cub3d.h"

typedef struct	s_main t_main;


//enum for the compas direction 

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

// typedef struct	s_angle
// {
// 	double	sin; // O/H
// 	double	cos; // A/H
// 	double	tan; // O/A
// }				t_angle;

typedef struct	s_player
{
	double	x;
	double	y;
	double	angle;
	//Standard — 90deg [π/2] is upward, 270deg [3π/2] is downward.
	//MinilibX — 90deg [π/2] is downward, 270deg [3π/2] is upward.
}				t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	g;
	int left;
	int right;
	int escp;
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
	void	*img_ptr;
	int		width;
	int		height;
}				t_texture;

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

typedef struct	s_wall_texture
{
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
}				t_wall_texture;
 
typedef struct s_map
{
	char			**map;
	unsigned int	height;
	unsigned int	width;

}				t_map; // Replaces the map array with the map structure ?

typedef struct	s_main
{
	void			*mlx_ptr;
	void			*mlx_win;
	char			**file_content;
	char			**id_and_info;
	t_map			map_struct;
	t_debug			debug;
	t_player		player;
	t_keys			keys;
	t_wall_texture	wall;
	t_colour		c_colour;
	t_colour		f_colour;
	int				final_colour;
	t_myimage		image;
}				t_main;

#endif