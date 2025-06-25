
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
void	put_pixel_to_image(t_main *main, int x, int y, int color)
{
	unsigned char		*dst;
	long				pixel_offset;
	t_myimage			*img;

	img = &main->image;
	pixel_offset = y * img->size_line + x * img->bytespp;
	if (pixel_offset > img->total_bytes)
	{
		printf("Coordinates %d and %d out of bounds: bigger than \
			%d bytes (total_image_bytes by %ld bytes\n", \
			x, y, img->total_bytes, pixel_offset);
		exit_cub3d(main, 1);
	}
	dst = img->addr + pixel_offset;
	*(unsigned int *)dst = color;
}

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
