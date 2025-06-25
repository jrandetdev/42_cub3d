
#include "cub3d.h"


int	get_fd(t_main *main, char *file_relative_path)
{
	int			fd;

	fd = open(file_relative_path, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			print_error_and_message("The required permissions \
				are denied for the file.\n");
			print_error_and_message("The required permissions"
				"are denied for the file.\n");
		exit_cub3d(main, 1);
	}
	return (fd);
}

bool	parsing(t_main *main, char *file_relative_path)
{
	int		fd;
	char	**file_content;

	if (is_dir(file_relative_path))
		exit_cub3d(main, 1);
	fd = get_fd(main, file_relative_path);
	file_content = get_file_content(main, fd, file_relative_path);
	extract_map_elements(main, file_content);
	get_map_descritpion(main, file_content);
	free_string_array(&file_content);
	is_map_valid(main);
	return (true);
}
