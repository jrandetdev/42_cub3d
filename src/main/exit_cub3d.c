/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:24:31 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/07 15:29:37 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all_pointer_arrays(t_main *main)
{
	if (main->map_struct.map)
		free_string_array(&main->map_struct.map);
	if (main->file_content)
		free_string_array(&main->file_content);
	if (main->id_and_info)
		free_string_array(&main->id_and_info);
}

void	free_all_textures(t_main *main)
{
	if (main->texture_bank.ea.texture_ptr)
		mlx_destroy_image(main->mlx_ptr, main->texture_bank.ea.texture_ptr);
	if (main->texture_bank.so.texture_ptr)
		mlx_destroy_image(main->mlx_ptr, main->texture_bank.so.texture_ptr);
	if (main->texture_bank.no.texture_ptr)
		mlx_destroy_image(main->mlx_ptr, main->texture_bank.no.texture_ptr);
	if (main->texture_bank.we.texture_ptr)
		mlx_destroy_image(main->mlx_ptr, main->texture_bank.we.texture_ptr);
	if (main->texture_bank.door.texture_ptr)
		mlx_destroy_image(main->mlx_ptr, main->texture_bank.door.texture_ptr);
	if (main->texture_bank.floor.texture_ptr)
		mlx_destroy_image(main->mlx_ptr, main->texture_bank.floor.texture_ptr);
	if (main->texture_bank.ceiling.texture_ptr)
		mlx_destroy_image(main->mlx_ptr,
			main->texture_bank.ceiling.texture_ptr);
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

void	exit_cub3d(t_main *main, char *error_message)
{
	if (main)
	{
		free_all_pointer_arrays(main);
		free_all_textures(main);
		free_mlx_pointers(main);
	}
	if (error_message)
	{
		print_error_and_message(error_message);
		if (errno)
			perror("Cub3d: ");
		exit(1);
	}
	exit(0);
}

int	handle_destroy(t_main *main)
{
	exit_cub3d(main, 0);
	return (0);
}
