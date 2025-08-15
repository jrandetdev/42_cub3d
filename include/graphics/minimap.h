/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:44:20 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:07:45 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

typedef struct s_vector	t_vector;
typedef struct s_main	t_main;

void		print_grid(t_main *main);
void		draw_player(t_main *main);
void		init_minimap(t_main *main);
void		print_minifov(t_main *main);
void		print_minimap(t_main *main);
void		print_minimap_base(t_main *main);
t_vector	mini_dda(t_main *main, float dst_x, float dst_y);

#endif