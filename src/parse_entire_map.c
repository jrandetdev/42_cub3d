/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entire_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:31:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/18 16:38:40 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_directory(char *file)
{
	int		fd;
	char	buffer[1];
	int		bytes_read;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	bytes_read = read(fd, buffer, 1);
	if (bytes_read == -1)
	{
		if (errno == EISDIR)
		{
			print_error_and_message("Input is a directory.\n");
			close (fd);
			return (false);
		}
	}
	close(fd);
	return (true);
}

int    get_fd_for_reading(char *s)
{
	int			fd;
	int			bytes_read;
	char		buffer[4];

	is_directory(s);
	fd = open(s, O_RDONLY);
	printf("fd is worth %d\n", fd);
	if (fd == -1)
		return (-1);
	bytes_read = read(fd, buffer, 1);
	if (bytes_read == -1)
	{
		if (errno == EISDIR)
		{
			print_error_and_message("Input is a directory.\n");
			close (fd);
		}
		return (-1);
	}
	return (fd);
}

bool	parsing(t_main *main, char *file)
{
	int		fd;

	fd = get_fd_for_reading(file);
	if (fd == -1)
		return (false);
	main->map = build_map(fd, file);
	if (!main->map)
		return (false);
	return (true);
}