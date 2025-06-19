/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:46:30 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/19 17:06:17 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @param addr contains all the information about the image. 
 * @struct t_my_image contains bitspp 
 * After creating an image, we can call `mlx_get_data_addr`, we pass
	bits_per_pixel`, `line_length`, and `endian` by reference. These will
	then be set accordingly for the *current* data address.

	We need to calculate the memory offset of the line length compared to 
	the actual window width (the image buffer vs window). To do this 
	img->bytespp is the unit we want to use 
	total bytes is the total amoutn of memory used  by the img buffer
 */
void	init_img(t_main *main)
{
	t_myimage	*img;

	img = &main->image;
	img->data_img = mlx_new_image(main->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!main->image.data_img)
	{
		exit_cub3d(main, 1);
	}
	img->addr = mlx_get_data_addr(
			img->data_img,
			&img->bitspp,
			&img->size_line,
			&img->endian);
	if (!img->addr)
	{
		exit_cub3d(main, 1);
		return ;
	}
	img->bytespp = img->bitspp / 8;
	img->pixels_per_line = img->size_line / img->bytespp;
	img->total_bytes = img->size_line * WIN_HEIGHT;
}
