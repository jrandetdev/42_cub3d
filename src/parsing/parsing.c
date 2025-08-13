/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:21:06 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 22:28:53 by jrandet          ###   ########.fr       */
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
	char	**file_content;

	check_if_dir(main, file_relative_path);
	extract_file_elements(main, file_relative_path, &file_content);
	parse_map_elements(main, file_content);
	load_personal_textures(main);
	get_map_descritpion(main, file_content);
	is_map_valid(main);
}
