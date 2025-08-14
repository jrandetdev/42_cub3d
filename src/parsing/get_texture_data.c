/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:14:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 23:55:25 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_data(t_main *main, t_texture *direc, char *xpm_file)
{
	direc->ptr = mlx_xpm_file_to_image(main->mlx_ptr, xpm_file,
			&direc->width, &direc->height);
	if (direc->width != direc->height)
		print_error_message(main, "Texture height and width need to be identical.");
	if (!direc->ptr)
		print_error_message(main, "Texture path not found or invalid.");
	direc->texture.addr = mlx_get_data_addr(
			direc->ptr,
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
