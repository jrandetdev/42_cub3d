/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:08:19 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/12 17:25:31 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	get_vec2(float x1, float y1, float x2, float y2)
{
	t_vec2	vector;

	vector.x = x2 - x1;
	vector.y = y2 - y1;
	return (vector);
}

float	get_vec2_norm(t_vec2 vec1, t_vec2 vec2)
{
	return (sqrt((pow(vec2.x - vec1.x, 2) + pow(vec2.y - vec1.y, 2))));
}
