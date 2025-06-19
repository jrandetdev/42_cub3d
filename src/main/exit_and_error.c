/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:56:50 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/19 16:44:36 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_and_message(char *error_message)
{
	printf("Error\n");
	ft_putstr_fd(error_message, 2);
}

void	exit_cub3d(t_main *main, int error_status)
{
	if (main)
	{
		if (main->map)
		{
			free_string_array(&main->map);
		}
		if (main->mlx_win)
		{
			mlx_destroy_window(main->mlx_ptr, main->mlx_win);
			main->mlx_win = NULL;
		}
		if (main->mlx_ptr)
		{
			mlx_destroy_display(main->mlx_ptr);
			main->mlx_ptr = NULL;
		}
	}
	if (errno > 0)
	{
		perror("Error ");
	}
	exit(error_status);
}

int	handle_destroy(t_main *main)
{
	exit_cub3d(main, 0);
	return (0);
}
