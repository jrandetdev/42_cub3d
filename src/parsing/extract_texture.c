
#include "cub3d.h"

static void	get_texture_data(t_main *main, t_texture *direc, char *xpm_file)
{
	direc->texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, xpm_file, \
		&direc->width, &direc->height);
	printf("%p\n", direc->texture_ptr);
		direc->texture.addr = mlx_get_data_addr(
		main->wall.no.texture_ptr,
		&direc->texture.bitspp,
		&direc->texture.size_line,
		&direc->texture.endian);
	if (!direc->texture.addr)
		exit_cub3d(main, "Mlx_get_data_addr failed.");
	direc->texture.bytespp = direc->texture.bitspp / 8;
	direc->texture.pixels_per_line = direc->texture.size_line / direc->texture.bytespp;
	direc->texture.total_bytes = direc->texture.size_line * main->wall.no.height;
}

void	extract_texture(t_main *main, char *id, char *xpm_f)
{
	if (!xmp_extension_is_valid(xpm_f, 3))
		return (exit_cub3d(main, "Texture file needs xpm extension."));
	if (ft_strncmp(id, "NO", 2) == 0)
		return (get_texture_data(main, &main->wall.no, xpm_f));
	else if (ft_strncmp(id, "SO", 2) == 0)
		return (get_texture_data(main, &main->wall.so, xpm_f));
	else if (ft_strncmp(id, "WE", 2) == 0)
		return (get_texture_data(main, &main->wall.we, xpm_f));
	else if (ft_strncmp(id, "EA", 2) == 0)
		return (get_texture_data(main, &main->wall.ea, xpm_f));
	else
		return (exit_cub3d(main, "Texture id needs NO, SO, WE, EA"));
}
