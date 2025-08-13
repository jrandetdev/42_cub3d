/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:21:06 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 23:29:24 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_fd(t_main *main, char *file)
{
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			print_error_syscall(main, "Open fd failed");
	}
	return (fd);
}

void	parsing(t_main *main, char *file)
{
	char	**file_content;

	check_if_file_is_dir(main, file);
	extract_file_elements(main, file, &file_content);
	extract_colour_and_texture(main, file_content);
	load_personal_texture(main, &main->assets.texture_bank.door,
		"./Assets/textures/cool_door.xpm");
	get_map_descritpion(main, file_content);
	free_string_array(&file_content);
	is_map_valid(main);
}
