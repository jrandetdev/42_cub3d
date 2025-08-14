/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:14:56 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 21:45:08 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	perform_checks_on_position(t_map *map, int x, int y);
static bool	verify_door_position(char **map, int x, int y);
static void	handle_invalid_map(t_map *map, char *message);

void	flood_fill(t_main *main, t_map *map, int x, int y)
{
	if (map->is_invalid)
		return ;
	perform_checks_on_position(map, x, y);
	if (map->array[y][x] == '1' || map->array[y][x] == 'V')
		return ;
	if (map->array[y][x] == DO || map->array[y][x] == DC)
	{
		if (!verify_door_position(map->array, x, y))
			return ;
	}
	map->array[y][x] = 'V';
	if (map->is_invalid == true)
		return ;
	flood_fill(main, map, x + 1, y);
	flood_fill(main, map, x, y + 1);
	flood_fill(main, map, x - 1, y);
	flood_fill(main, map, x, y - 1);
	flood_fill(main, map, x + 1, y + 1);
	flood_fill(main, map, x - 1, y - 1);
	flood_fill(main, map, x + 1, y - 1);
	flood_fill(main, map, x - 1, y + 1);
}

static void	perform_checks_on_position(t_map *map, int x, int y)
{
		if (x < 0 || y < 0)
	{
		handle_invalid_map(map, "Map cannot have negative values");
		return ;
	}
	if (y >= map->height || x >= map->width)
	{
		handle_invalid_map(map, "Player can escape map.");
		return ;
	}
	if (map->array[y][x] == ' ' || map->array[y][x] == '\t')
	{
		handle_invalid_map(map, "Map contains spaces and is not enclosed.");
		return ;
	}
	if (map->array[y][x] == '\0')
	{
		handle_invalid_map(map, "Map contains null characters.");
		return ;
	}
}

static bool	verify_door_position(char **map, int x, int y)
{
	if ((map[y][x + 1] == '1' && map[y][x - 1] == '1')
		|| (map[y + 1][x] == '1' && map[y - 1][x] == '1'))
		return (true);
	return (false);
}

static void	handle_invalid_map(t_map *map, char *message)
{
	map->is_invalid = true;
	print_error();
	ft_putendl_fd(message, 2);
}
