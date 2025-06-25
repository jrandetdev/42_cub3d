
#include "cub3d.h"

static void	get_texture_data(t_main *main, t_texture *direc, char *xpm_file)
{
	direc->img_ptr = mlx_xpm_file_to_image(main->mlx_ptr, xpm_file, \
		&direc->width, &direc->height);
}

bool	extract_texture(t_main *main, char *identifier, char *xpm_file)
{
	if (is_dir(xpm_file))
		return (false);
	if (!xmp_extension_is_valid(xpm_file, 3))
		return (false);
	if (ft_strncmp(identifier, "NO", 2) == 0)
		return (get_texture_data(main, &main->wall.no, xpm_file), true);
	else if (ft_strncmp(identifier, "SO", 2) == 0)
		return (get_texture_data(main, &main->wall.so, xpm_file), true);
	else if (ft_strncmp(identifier, "WE", 2) == 0)
		return (get_texture_data(main, &main->wall.we, xpm_file), true);
	else if (ft_strncmp(identifier, "EA", 2) == 0)
		return (get_texture_data(main, &main->wall.ea, xpm_file), true);
	else
	{
		print_error_and_message("Texture idenfifier is invalid. Please use \
			NO, SO, EA, or WE.\n");
		return (false);
	}
}
