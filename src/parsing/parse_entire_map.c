/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entire_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:31:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/23 18:31:24 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_dir(t_main *main)
{
	int			fd;
	int			bytes_read;
	char		buffer[1];

	fd = open(s, O_RDONLY);
	if (fd == -1)
		exit_cub3d(main, 1);
	bytes_read = read(fd, buffer, 1);
	if (bytes_read == -1)
	{
		if (errno == EISDIR)
			print_error_and_message("Input is a directory.\n");
		close(fd);
		return (true);
	}
	close(fd);
	return (false);
}

int	get_fd(t_main *main, char *file_name)
{
	int			fd;

	if (is_dir)
		exit_cub3d(main, 1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_cub3d(main, 1);
	return (fd);
}

bool	parsing(t_main *main, char *file_relative_path)
{
	int		fd;
	char	**file_content;

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
