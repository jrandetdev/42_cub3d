/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:30:17 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/30 18:16:17 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_in_door_half(t_main *main, t_dda_struct *dda)
{
	double	width_pourcentage;
	double	width_pos_x;

	(void)main;
	if (dda->side == 0)
		width_pos_x = main->player.y + main->ray.dirY * dda->perpwalldist;
	else
		width_pos_x = main->player.x + main->ray.dirX * dda->perpwalldist;
	width_pourcentage = width_pos_x - floor(width_pos_x);
	if (width_pourcentage > 0.5)
		return (true);
	return (false);
}
//par frame ouvrir de deux pixel et ca donne l'effet de portwes coulissantes 
//deduire les pixe
//decaler dans la texture et faire une translation et partir a droite 
//but de faire le plus fluide possible 