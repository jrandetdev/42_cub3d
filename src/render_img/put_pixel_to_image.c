/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:55:50 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 21:18:11 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * the pixel offset, is because its like a 2 dimenssional arrazy stretched out
 * if you are looking for the 3rd row, i.e. y = 3 then you yould need 
 * to know the size of the line in bytes to know by how many lines you need 
 * to hop by. Then let's say you are somewhere on that row in between
 * the begining and end of the line size. You would move by x bytes in 
 * the column space to get to your x coordinate. 
 * 
 * So this is how you translate coordinates on an x y plane on an image 
 * buffer :)
 * @param dst is the destination where you want to go in the 
 * image buffer.
 * @param pixel_offset is by how many pixels from the origin (img->addr) 
 * we have to move until we get to the exact yth row(or line of pixels)
 * and x pixels to the right. 
 * @struct t_my_image is needed to have the information about the 
 * image which is then used in our own put_pixel_to_image function
 * which is more precise than the mlx_put_pixel.
 * 
 * edge cases : if the offset you calculates is bigger than the 
 * buffer, then you are out of bounds. 
 */
void	put_pixel_to_image(t_main *main, int x, int y, int colour)
{
	unsigned char		*dst;
	long				pixel_offset;
	t_image			*img;

	img = &main->image;
	pixel_offset = y * img->size_line + x * img->bytespp;
	if (pixel_offset > img->total_bytes)
		print_error_message(main, "Coordinates are outside of map capacity.");
	dst = img->addr + pixel_offset;
	*(unsigned int *)dst = colour;
}
