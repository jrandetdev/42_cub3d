/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:21:00 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/12 17:28:50 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialise_north_and_south(t_main *main)
{
	float	fov;

	fov = (float)FOV / 100;
	if (ft_strncmp(main->player.cardinal_direction, "N", 1) == 0)
	{
		main->player.dir_x = 0;
		main->player.dir_y = -1;
		main->player.plane_x = fov;
		main->player.plane_y = 0;
	}
	if (ft_strncmp(main->player.cardinal_direction, "S", 1) == 0)
	{
		main->player.dir_x = 0;
		main->player.dir_y = 1;
		main->player.plane_x = -fov;
		main->player.plane_y = 0;
	}
}

static void	initialise_east_and_west(t_main *main)
{
	float	fov;

	fov = (float)FOV / 100;
	if (ft_strncmp(main->player.cardinal_direction, "E", 1) == 0)
	{
		main->player.dir_x = 1;
		main->player.dir_y = 0;
		main->player.plane_x = 0;
		main->player.plane_y = fov;
	}
	if (ft_strncmp(main->player.cardinal_direction, "W", 1) == 0)
	{
		main->player.dir_x = -1;
		main->player.dir_y = 0;
		main->player.plane_x = 0;
		main->player.plane_y = -fov;
	}
}

static void	init_player_direction(t_main *main)
{
	initialise_north_and_south(main);
	initialise_east_and_west(main);
	main->player.angle = atan2(main->player.dir_y, main->player.dir_x);
}

static bool	get_players(t_main *main, int *x, int *y, int *player)
{
	int		i;
	int		j;
	char	**map;

	map = main->map_struct.map;
	j = -1;
	while (map[++j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!ft_strchr("0123NSWE' ", map[j][i]))
				return (print_error_message(main, "Map characters needs to be NSEW or 012"), false);
			if (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E')
			{
				*x = i;
				*y = j;
				main->player.cardinal_direction = &(map[j][i]);
				(*player)++;
			}
			i++;
		}
	}
	return (true);
}

bool	find_player_position(t_main *main, int *x, int *y, int *player)
{
	if (!get_players(main, x, y, player))
		return (false);
	if (*player != 1)
	{
		if (*player < 1)
			print_error_message(main, "No player found");
		else if (*player > 1)
			print_error_message(main, "Too many players, it's a single-player game");
		return (false);
	}
	main->player.x = *x + 0.5;
	main->player.y = *y + 0.5;
	init_player_direction(main);
	main->map_struct.map[*y][*x] = '0';
	return (true);
}
