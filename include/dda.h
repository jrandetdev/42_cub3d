/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:22:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 18:25:19 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

typedef struct s_vector
{
	float	x;
	float	y;
}			t_vector;

typedef struct s_dda
{
	int			x;
	int			y;
	int			hit;
	int			side;
	int			step_x;
	int			step_y;
	float		delta_x;
	float		delta_y;
	t_vector	ray;
	float		camera_x;
	float		dist_to_x_int;
	float		dist_to_y_int;
	float		correct_distance;
	float		door_hit_percentage;
}				t_dda;

typedef struct s_mini_dda
{
	float	m;
	float	x_1;
	float	y_1;
	float	x_2;
	float	y_2;
	float	delta_x;
	float	delta_y;
}			t_mini_dda;

#endif