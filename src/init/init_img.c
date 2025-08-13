/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:17:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 21:18:34 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_main *main)
{
	t_image	*img;

	img = &main->image;
	img->data_img = mlx_new_image(main->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!main->image.data_img)
		print_error_syscall(main, "Mlx_new_image failed");
	img->addr = mlx_get_data_addr(
			img->data_img,
			&img->bitspp,
			&img->size_line,
			&img->endian);
	if (!img->addr)
		print_error_syscall(main, "Mlx_get_data_addr failed");
	img->bytespp = img->bitspp / 8;
	img->pixels_per_line = img->size_line / img->bytespp;
	img->total_bytes = img->size_line * WIN_HEIGHT;
}
