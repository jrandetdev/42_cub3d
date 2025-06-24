/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:59:43 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/24 13:51:23 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

#include "cub3d.h"

typedef struct	s_main t_main;

typedef struct s_debug
{
	bool	debug;
	int		tile_size;
}	t_debug;

typedef struct	s_player
{
	double	x;
	double	y;
	double	angle;
}				t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	g;
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

typedef struct s_texture
{
	void	*texture;
	int		x_size;
	int		y_size;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_textures_bank
{
	t_texture		no;
	t_texture		so;
	t_texture		ea;
	t_texture		we;
	t_color			c;
	t_color			f;
}	t_textures_bank;

typedef struct s_map
{
	char			**map;
	unsigned int	height;
	unsigned int	width;

}	t_map; // Replaces the map array with the map structure ?

typedef struct	s_main
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_map			map_struct;
	t_debug			debug;
	t_player		player;
	t_keys			keys;
	t_myimage		image;
}				t_main;

#endif