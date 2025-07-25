/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_interaction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:04:12 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/25 14:22:41 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_interaction(t_main *main)
{
	int	x;
	int	y;

	x = (int)trunc(main->player.x);
	y = (int)trunc(main->player.y);
	if (main->keys.e)
	{
		if (main->map_struct.map[y][x + 1] == DC)
			main->map_struct.map[y][x + 1] = DO;
		else if (main->map_struct.map[y][x - 1] == DC)
			main->map_struct.map[y][x - 1] = DO;
		else if (main->map_struct.map[y + 1][x] == DC)
			main->map_struct.map[y + 1][x] = DO;
		else if (main->map_struct.map[y - 1][x] == DC)
			main->map_struct.map[y - 1][x] = DO;
		else if (main->map_struct.map[y][x + 1] == DO)
			main->map_struct.map[y][x + 1] = DC;
		else if (main->map_struct.map[y][x - 1] == DO)
			main->map_struct.map[y][x - 1] = DC;
		else if (main->map_struct.map[y + 1][x] == DO)
			main->map_struct.map[y + 1][x] = DC;
		else if (main->map_struct.map[y - 1][x] == DO)
			main->map_struct.map[y - 1][x] = DC;
	}
	main->keys.e = 0;
}