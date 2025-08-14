/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:39:34 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 19:40:46 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

void	player_movement(t_main *main);
void	player_rotation(t_main *main);
void	valid_next_movement_up(t_main *main, float next_x, float next_y);
void	valid_next_movement_down(t_main *main, float next_x,
			float next_y);
void	valid_next_movement_left(t_main *main, float next_x,
			float next_y);
void	valid_next_movement_right(t_main *main, float next_x,
			float next_y);

#endif