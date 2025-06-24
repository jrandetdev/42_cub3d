/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entire_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:31:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/24 13:11:56 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @param file_relative_path is the relative path to the file you are checking
 * the access to. 
 * GOAL: use the open function with O_DIRECTORY to check if the file is a dir.
 * if it opens the file and the fd is positive, then it succeeded and the file
 * is a directory. In this case we return true because it is dir.
 */
bool	is_dir(char *file_relative_path)
{
	int	fd;

	fd = open(file_relative_path, O_DIRECTORY);
	if (fd > 0)
	{
		print_error_and_message("The named file is a directory.\n");
		close(fd);
		return (true);
	}
	return (false);
}

int	get_fd(t_main *main, char *file_relative_path)
{
	int			fd;

	fd = open(file_relative_path, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			print_error_and_message("The required permissions are denied for the file.\n");
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
	print_array(file_content);
	get_map_descritpion(main, file_content);
	parse_player_and_texture(main, file_content);
	free_string_array(&file_content);
	if (!is_map_valid(main->map_struct.map))
		exit_cub3d(main, EXIT_FAILURE);
	return (true);
}
