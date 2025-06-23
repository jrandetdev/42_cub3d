/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:06:49 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/23 14:49:31 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../include/cub3d.h"

static size_t	get_max_row_size(char **map) //double commande
{
	size_t	len;
	size_t	max_len;

	max_len = 0;
	while(*map)
	{
		len = ft_strlen(*map);
		if (len > max_len)
			max_len = len;
		map++;
	}
	printf("%ld\n", len);
	return (len);
}

static void	print_colum(t_main *main, float x)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		mlx_pixel_put(main->mlx_ptr, main->mlx_win, x, y, 0xFFFFF);
		y++;
	}
}

void	print_lines(t_main *main, float y)
{
	int	x;

	x = 0;
	while(x < WIN_WIDTH)
	{
		mlx_pixel_put(main->mlx_ptr, main->mlx_win, x, y, 0xFFFFF);
		x++;
	}
}

void	print_grid(t_main *main)
{
	float	x;
	float	y;
	float	separator;
	int	height = count_map_height(main->map_struct.map); //debug
	int	width = get_max_row_size(main->map_struct.map); //debug

	
	x = 0;
	y = 0;
	if (height < width)
		separator = WIN_HEIGHT / height;
	else
		separator = WIN_WIDTH / width;
	while(x < WIN_WIDTH)
	{
		print_colum(main, x);
		x += separator;
	}
	while(y < WIN_HEIGHT)
	{
		print_lines(main, y);
		y += separator;
	}
}