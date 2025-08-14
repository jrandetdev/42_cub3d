/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:24:31 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/14 11:05:45 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all_pointer_arrays(t_main *main)
{
	if (main->map_struct.map)
		free_string_array(&main->map_struct.map);
}

void	free_all_textures(t_main *main)
{
	if (main->assets.texture_bank.ea.ptr)
		mlx_destroy_image(main->mlx_ptr, main->assets.texture_bank.ea.ptr);
	if (main->assets.texture_bank.so.ptr)
		mlx_destroy_image(main->mlx_ptr, main->assets.texture_bank.so.ptr);
	if (main->assets.texture_bank.no.ptr)
		mlx_destroy_image(main->mlx_ptr, main->assets.texture_bank.no.ptr);
	if (main->assets.texture_bank.we.ptr)
		mlx_destroy_image(main->mlx_ptr, main->assets.texture_bank.we.ptr);
	if (main->assets.texture_bank.door.ptr)
		mlx_destroy_image(main->mlx_ptr, main->assets.texture_bank.door.ptr);
	if (main->assets.texture_bank.floor.ptr)
		mlx_destroy_image(main->mlx_ptr, main->assets.texture_bank.floor.ptr);
	if (main->assets.texture_bank.ceiling.ptr)
		mlx_destroy_image(main->mlx_ptr,
			main->assets.texture_bank.ceiling.ptr);
}

void	free_mlx_pointers(t_main *main)
{
	if (main->image.data_img)
		mlx_destroy_image(main->mlx_ptr, main->image.data_img);
	if (main->mlx_win)
	{
		mlx_destroy_window(main->mlx_ptr, main->mlx_win);
		main->mlx_win = NULL;
	}
	if (main->mlx_ptr)
	{
		mlx_destroy_display(main->mlx_ptr);
		free(main->mlx_ptr);
	}
}

void	exit_cub3d(t_main *main, int exit_code)
{
	if (main)
	{
		free_all_pointer_arrays(main);
		free_all_textures(main);
		free_mlx_pointers(main);
	}
	exit(exit_code);
}

int	handle_destroy(t_main *main)
{
	exit_cub3d(main, 0);
	return (0);
}
