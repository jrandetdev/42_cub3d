/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:29:04 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 17:29:14 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	get_corresp_texture(t_main *main, t_dda *dda)
{
	t_texture	texture;

	if (dda->hit == 2 || dda->hit == 3)
	{
		texture = main->assets.texture_bank.door;
		return (texture);
	}
	if (dda->side == 0)
	{
		if (dda->ray.x > 0)
			texture = main->assets.texture_bank.ea;
		else
			texture = main->assets.texture_bank.we;
	}
	else
	{
		if (dda->ray.y < 0)
			texture = main->assets.texture_bank.no;
		else
			texture = main->assets.texture_bank.so;
	}
	return (texture);
}
