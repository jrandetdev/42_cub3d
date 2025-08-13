/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:21:06 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 20:39:15 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_fd(t_main *main, char *file_relative_path)
{
	int			fd;

	fd = open(file_relative_path, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			print_error_syscall(main, "Open fd failed");
	}
	return (fd);
}

void	parsing(t_main *main, char *file_relative_path)
{
	int		fd;
	char	**file_content;

	is_dir(main, file_relative_path);
	fd = get_fd(main, file_relative_path);
	file_content = get_file_content(main, fd, file_relative_path);
	close(fd);
	parse_map_elements(main, file_content);
	load_personal_textures(main);
	get_map_descritpion(main, file_content);
	is_map_valid(main);
}
