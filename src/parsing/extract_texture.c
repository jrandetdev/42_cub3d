
#include "cub3d.h"

static void	get_texture_data(t_main *main, t_texture *direc, char *xpm_file)
{
	direc->img_ptr = mlx_xpm_file_to_image(main->mlx_ptr, xpm_file, \
		&direc->width, &direc->height);
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
		return (exit_cub3d(main, "Wrong texture format, need NO, SO, WE, EA + .xpm file."));
}
