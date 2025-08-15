/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:06:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 17:48:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

typedef struct s_image
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
	void		*ptr;
	int			width;
	int			height;
	t_image		texture;
}				t_texture;

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

#endif