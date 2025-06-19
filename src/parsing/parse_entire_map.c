/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entire_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:31:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/19 13:10:04 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_fd(t_main *main, char *s)
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
		exit_cub3d(main, 1);
	}
	close(fd);
	fd = open(s, O_RDONLY);
	if (fd == -1)
		exit_cub3d(main, 1);
	return (fd);
}

bool	parsing(t_main *main, char *file)
{
	int		fd;

	fd = get_fd(main, file);
	build_map(main, fd, file);
	return (true);
}
