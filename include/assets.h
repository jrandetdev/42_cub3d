#ifndef ASSETS_H
# define ASSETS_H

typedef struct s_image t_image;

typedef struct s_texture
{
	void		*texture_ptr;
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