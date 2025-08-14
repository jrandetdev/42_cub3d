/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_is_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:08:53 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 23:07:16 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_if_map_is_valid(t_main *main)
{
	t_map	*map;
	int		x;
	int		y;

	map = &main->map;
	x = 0;
	y = 0;
	if (!find_player_position(main, &x, &y, &map->player))
		print_error_message(main, "Player not found in given map->");
	flood_fill(main, map, x, y);
	if (map->is_invalid)
		print_error_message(main, "Map is invalid.");
}
