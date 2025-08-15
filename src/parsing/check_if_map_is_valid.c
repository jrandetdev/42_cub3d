/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_is_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:08:53 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:12:46 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_if_map_is_valid(t_main *main)
{
	t_map			*map;
	int				x;
	int				y;
	t_flood_fill	flood_fill;

	map = &main->map;
	x = 0;
	y = 0;
	if (!find_player_position(main, &x, &y, &map->player))
		print_error_message(main, "Player not found in given map->");
	flood_fill.map = copy_map(map);
	if (!flood_fill.map)
		print_error_syscall(main, "flood_fill map allocation failed");
	flood_fill.height = main->map.height;
	flood_fill.width = main->map.width;
	flood_fill.is_invalid = false;
	ft_flood_fill(main, &flood_fill, x, y);
	safe_free_tab((void ***)&flood_fill.map);
	if (map->is_invalid)
		exit_cub3d(main, EXIT_FAILURE);
}
