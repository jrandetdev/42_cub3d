/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:14:56 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 17:15:05 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	perform_checks(t_flood_fill	*flood_fill, int x, int y);
static bool	verify_door_position(char **map, int x, int y);
static void	check_all_directions(t_main *main, t_flood_fill *ff, int x, int y);
static void	handle_invalid_map(t_flood_fill *flood_fill, char *message);

void	ft_flood_fill(t_main *main, t_flood_fill *flood_fill, int x, int y)
{
	if (flood_fill->is_invalid == true)
		return ;
	perform_checks(flood_fill, x, y);
	if (flood_fill->map[y][x] == '1' || flood_fill->map[y][x] == 'V')
		return ;
	if (flood_fill->map[y][x] == DO || flood_fill->map[y][x] == DC)
	{
		if (!verify_door_position(flood_fill->map, x, y))
			flood_fill->is_invalid = true;
	}
	flood_fill->map[y][x] = 'V';
	check_all_directions(main, flood_fill, x, y);
}

static void	perform_checks(t_flood_fill	*flood_fill, int x, int y)
{
	if (x < 0 || y < 0)
	{
		handle_invalid_map(flood_fill, "Map cannot have negative values");
		return ;
	}
	if (y >= flood_fill->height || x >= flood_fill->width)
	{
		handle_invalid_map(flood_fill, "Player can escape map.");
		return ;
	}
	if (flood_fill->map[y][x] == ' ')
	{
		handle_invalid_map(flood_fill, "Map contains a space char.");
		return ;
	}
	if (flood_fill->map[y][x] == '\t')
	{
		handle_invalid_map(flood_fill, "Map contains a tab char..");
		return ;
	}
	if (flood_fill->map[y][x] == '\0')
	{
		handle_invalid_map(flood_fill, "Map contains null characters.");
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

static void	check_all_directions(t_main *main, t_flood_fill *ff, int x, int y)
{
	ft_flood_fill(main, ff, x + 1, y);
	ft_flood_fill(main, ff, x, y + 1);
	ft_flood_fill(main, ff, x - 1, y);
	ft_flood_fill(main, ff, x, y - 1);
	ft_flood_fill(main, ff, x + 1, y + 1);
	ft_flood_fill(main, ff, x - 1, y - 1);
	ft_flood_fill(main, ff, x + 1, y - 1);
	ft_flood_fill(main, ff, x - 1, y + 1);
}

static void	handle_invalid_map(t_flood_fill *flood_fill, char *message)
{
	flood_fill->is_invalid = true;
	print_error();
	ft_putendl_fd(message, 2);
}
