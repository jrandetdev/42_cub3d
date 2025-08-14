/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:52:11 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 19:52:31 by jrandet          ###   ########.fr       */
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
