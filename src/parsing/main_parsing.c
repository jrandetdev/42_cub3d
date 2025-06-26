
#include "cub3d.h"


int	get_fd(t_main *main, char *file_relative_path)
{
	int			fd;

	fd = open(file_relative_path, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			exit_cub3d(main, "No permissions for file.");
	}
	return (fd);
}

bool	parsing(t_main *main, char *file_relative_path)
{
	int		fd;

	if (is_dir(file_relative_path))
		exit_cub3d(main, "Input is a directory.");
	fd = get_fd(main, file_relative_path);
	main->file_content = get_file_content(main, fd, file_relative_path);
	parse_map_elements(main);
	get_map_descritpion(main);
	free_string_array(&main->file_content);
	is_map_valid(main);
	return (true);
}
