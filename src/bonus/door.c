/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/04 17:16:21 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	opening_door(t_main *main)
{
	int		x;
	int		y;
	char	**map;

	main->keys.e = 0;
	map = main->map_struct.map;
	x = (int)trunc(main->player.x + (main->player.dir_x * 1.0));
	y = (int)trunc(main->player.y + (main->player.dir_y * 1.0));
	if (main->map_struct.map[y][x] == DC)
		main->map_struct.map[y][x] = DA;
	else if (main->map_struct.map[y][x] == DO)
	{
		if (map[(int)trunc(main->player.y)][(int)trunc(main->player.x)] == map[y][x])
			return;
		main->map_struct.map[y][x] = DA;
	}
}

bool is_in_door_half(t_main *main, t_dda_struct *dda)
{
	double		width_pourcentage;
	double		width_pos_x;

	if (dda->side == 0)
		width_pos_x = main->player.y + dda->ray_diry * dda->perpwalldist;
	else
		width_pos_x = main->player.x + dda->ray_dirx * dda->perpwalldist;
	width_pourcentage = width_pos_x - floor(width_pos_x);
	if (width_pourcentage > 0.5)
		return (true);
	return (false);
}
//par frame ouvrir de deux pixel et ca donne l'effet de portwes coulissantes 
//deduire les pixe
//decaler dans la texture et faire une translation et partir a droite 
//but de faire le plus fluide possible make 
