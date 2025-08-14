/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:08:19 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 16:53:57 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	get_vec2(float x1, float y1, float x2, float y2)
{
	t_vector	vector;

	vector.x = x2 - x1;
	vector.y = y2 - y1;
	return (vector);
}

float	get_vec2_norm(t_vector vec1, t_vector vec2)
{
	return (sqrt((pow(vec2.x - vec1.x, 2) + pow(vec2.y - vec1.y, 2))));
}
