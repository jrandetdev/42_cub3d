/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:20:40 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/12 17:20:40 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_data(t_main *main, t_texture *direc, char *xpm_file)
{
	direc->texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, xpm_file,
			&direc->width, &direc->height);
	if (direc->width != direc->height)
		print_error_message(main, "Texture height and width need to be identical.");
	if (!direc->texture_ptr)
		print_error_message(main, "Texture path not found or invalid.");
	direc->texture.addr = mlx_get_data_addr(
			direc->texture_ptr,
			&direc->texture.bitspp,
			&direc->texture.size_line,
			&direc->texture.endian);
	if (!direc->texture.addr)
		print_error_syscall(main, "Mlx_get_data_addr failed");
	direc->texture.bytespp = direc->texture.bitspp / 8;
	direc->texture.pixels_per_line = direc->texture.size_line
		/ direc->texture.bytespp;
	direc->texture.total_bytes = direc->texture.size_line * direc->height;
}

static bool	check_texture_id(t_main *main, void *texture_ptr)
{
	if (texture_ptr)
		print_error_message(main, "Direction cannot be used twice");
	return (true);
}

void	extract_texture(t_main *main, char *id, char *xpm_f)
{
	if (!xmp_extension_is_valid(xpm_f, 3))
		print_error_message(main, "Texture file needs xpm extension.");
	if (ft_strncmp(id, "NO", 2) == 0
		&& check_texture_id(main, main->assets.texture_bank.no.texture_ptr))
		get_texture_data(main, &main->assets.texture_bank.no, xpm_f);
	else if (ft_strncmp(id, "SO", 2) == 0  && !main->assets.texture_bank.so.texture_ptr
		&& check_texture_id(main, main->assets.texture_bank.so.texture_ptr))
		get_texture_data(main, &main->assets.texture_bank.so, xpm_f);
	else if (ft_strncmp(id, "WE", 2) == 0 && !main->assets.texture_bank.we.texture_ptr
		&& check_texture_id(main, main->assets.texture_bank.we.texture_ptr))
		get_texture_data(main, &main->assets.texture_bank.we, xpm_f);
	else if (ft_strncmp(id, "EA", 2) == 0 && !main->assets.texture_bank.ea.texture_ptr
		&& check_texture_id(main, main->assets.texture_bank.ea.texture_ptr))
		get_texture_data(main, &main->assets.texture_bank.ea, xpm_f);
	else
		print_error_message(main, "Texture id needs to be NO, SO, WE, EA");
}

void	check_and_get_texture(t_main *main, t_texture *pannel, char *filename)
{
	if (!xmp_extension_is_valid(filename, 3))
		print_error_message(main, "Texture file needs xpm extension.");
	get_texture_data(main, pannel, filename);
}

void	load_personal_textures(t_main *main)
{
	check_and_get_texture(main, &main->assets.texture_bank.door,
		"./Assets/textures/cool_door.xpm");
}
