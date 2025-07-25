/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_interaction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:04:12 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/25 15:41:10 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_interaction(t_main *main)
{
	int		x;
	int		y;
	char	**map;

	if (main->keys.e)
	{
		main->keys.e = 0;
		map = main->map_struct.map;
		x = (int)trunc(main->player.x + (main->player.dir_x * 1.5));
		y = (int)trunc(main->player.y + (main->player.dir_y * 1.5));
		if (main->map_struct.map[y][x] == DC)
			main->map_struct.map[y][x] = DO;
		else if (main->map_struct.map[y][x] == DO)
		{
			if (map[(int)trunc(main->player.y)][(int)trunc(main->player.x)] == map[y][x])
				return;
			main->map_struct.map[y][x] = DC;
		}
	}
}