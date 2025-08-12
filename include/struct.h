/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:54:48 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/12 18:50:13 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "dda.h"
# include "bonus_struct.h"

/*---------------------------------- ENUM ------------------------------------*/
enum e_start_angle
{
	N = 0,
	E = 90,
	S = 180,
	W = 270,
};

/*---------------------------------- UNION -----------------------------------*/
typedef union s_coulour
{
	int	value;
	struct
	{
		char	r;
		char	g;
		char	b;
		char	a;
	};
}	t_colour;

/*--------------------------------- STRUCT -----------------------------------*/

typedef struct s_vec2
{
	float	x;
	float	y;
}			t_vec2;

typedef struct s_ray
{
	float	dirx;
	float	diry;
}			t_ray;

typedef struct s_map
{
	char			**map;
	unsigned int	height;
	unsigned int	width;

}					t_map;

typedef struct s_minimap
{
	int	start_px;
	int	start_py;
	int	tile_size;
	int	map_size_x;
	int	map_size_y;
}		t_minimap;

typedef struct s_parsing
{
	int		player;
	int		patern;
	char	**map;
	int		map_width;
	int		map_height;
}			t_parsing;

typedef struct s_params
{
	int		start;
	int		screen_x;
	int		screen_y;
	int		draw_end;
	int		texture_x;
	int		draw_start;
	int		wall_height;
	float	step;
}			t_params;

typedef struct s_cal
{
	int		half_wh;
	int		half_ww;
	float	pre_fov;
	float	cf_ray_dirx_left;
	float	cf_ray_diry_left;
	float	cf_ray_dirx_right;
	float	cf_ray_diry_right;
	float	cf_pre_step_right;
	float	cf_pre_step_down;
}			t_cal;

typedef struct s_myimage
{
	void	*data_img;
	void	*addr;
	int		bitspp;
	int		bytespp;
	int		size_line;
	int		total_bytes;
	int		pixels_per_line;
	int		endian;
}			t_image;

typedef struct s_texture
{
	void		*texture_ptr;
	int			width;
	int			height;
	t_image		texture;
}				t_texture;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	camera_x;
	float	camera_y;
	char	*cardinal_direction;
}			t_player;

typedef struct s_texture_bank
{
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
	t_texture		door;
	t_texture		floor;
	t_texture		ceiling;
}					t_texture_bank;

typedef struct s_guide
{
	int		texture_x;
	int		texture_y;
	int		pixel_distance_down;
	float	pos_z;
	float	x_step_right;
	float	y_step_down;
	float	floor_coor_x;
	float	floor_coor_y;
	float	distance_to_row;
	float	floor_pannel_distance;
	int		color;
	int		floor_grid_x;
	int		floor_grid_y;
}			t_guide;

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
	int	escp;
	int	down;
	int	left;
	int	right;
	int	enter;
	int	shift;
}		t_keys;

typedef struct s_assets
{
	t_door				door;
	t_texture_bank		texture_bank;
	t_colour			c_colour;
	t_colour			f_colour;
}		t_assets;

typedef struct s_interactions
{
	t_mouse				mouse;
	t_keys				keys;
}		t_interactions;

typedef struct s_main
{
	int					menu;
	int					game_start;
	void				*mlx_ptr;
	void				*mlx_win;
	t_assets			assets;
	t_cal				cal;
	t_bonus				bonus;
	t_image				image;
	t_interactions		interaction;
	t_menu_param		param;
	t_player			player;
	t_minimap			minimap;
	t_mini_dda			mini_dda;
	t_map				map_struct;
	
}						t_main;

typedef struct s_threads
{
	pthread_t	thread_id;
	int			start;
	int			end;
	t_main		*main;
}				t_threads;

#endif