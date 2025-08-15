/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:14:49 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:15:13 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_if_file_is_dir(t_main *main, char *file_relative_path)
{
	int	fd;

	fd = open(file_relative_path, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		print_error_message(main, "The file is a directory.");
	}
}
