/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:20:33 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/22 15:20:35 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @param file_relative_path is the relative path to the file you are checking
 * the access to. 
 * GOAL: use the open function with O_DIRECTORY to check if the file is a dir.
 * if it opens the file and the fd is positive, then it succeeded and the file
 * is a directory. In this case we return true because it is dir.
 * We close the fd only if it is dir, otherwise open failed
 */
bool	is_dir(char *file_relative_path)
{
	int	fd;

	fd = open(file_relative_path, O_DIRECTORY);
	if (fd > 0)
	{
		print_error_and_message("The file is a directory.\n");
		close(fd);
		return (true);
	}
	return (false);
}

/**
 * Both the functions check the extension of the file to know if it is the
 * correct format.
 */
bool	cub_extension_is_valid(char	*s, int len)
{
	while (*s)
		s++;
	s--;
	if (*s != 'b')
		return (false);
	while (len--)
		s--;
	if (ft_strncmp(s, ".cub", 4) == 0)
		return (true);
	return (false);
}

bool	xmp_extension_is_valid(char	*s, int len)
{
	while (*s)
		s++;
	s--;
	if (*s != 'm')
		return (false);
	while (len--)
		s--;
	if (ft_strncmp(s, ".xpm", 4) == 0)
		return (true);
	return (false);
}
