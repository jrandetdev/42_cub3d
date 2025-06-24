/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:24:08 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/24 14:02:07 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_tile_size(t_main *main)
{
	if (main->map_struct.height > main->map_struct.width)
		main->debug.tile_size = WIN_HEIGHT / main->map_struct.height;
	else
		main->debug.tile_size = WIN_WIDTH / main->map_struct.width;
}

void	init_debug(t_main *main)
{
	get_tile_size(main);
}

void	print_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}