/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_desription.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:10:09 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/19 17:11:38 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	count_map_height(char **map)
{
	int	i;

	i = 0;
	while(map[i])
		i++;
	return (i);
}

static void	flood_fill(char **map, int player, int x, int y, int *valid)
{
	if (*valid == 0)
		return ;
	if (x < 0 || y < 0 || map[y][x] == '\0' || map[y][x] == ' ')
	{
		*(valid) = 0;
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	if (map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		player++;
	map[y][x] = 'V';
	flood_fill(map, player, x++, y, valid);
	flood_fill(map, player, x, y++, valid);
	flood_fill(map, player, --x, y, valid);
	flood_fill(map, player, x, --y, valid);
	//corner not be good
}

static char	**copy_map(char **map, char **new_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	new_map = ft_calloc(count_map_height(map) + 1, sizeof(char*));
	if (!new_map)
		exit(EXIT_FAILURE); //exit cub3d
	while (map[i])
	{
		new_map[j++] = ft_strdup(map[i++]);
		if (!new_map)
		{
			//free new_map
			exit(EXIT_FAILURE);//exit cub3d
		}
	}
	return (new_map);
}

bool	is_map_valid(char **map)
{
	int		valid;
	int		player;
	char	**reviewed_map;

	valid = 1;
	player = 0;
	reviewed_map = NULL;
	reviewed_map = copy_map(map, reviewed_map);
	flood_fill(reviewed_map, player, 10, 3, &valid);
	
	if (player != 1)
	{
		printf("wrong player number %d\n", player);
		return (false);
	}
	printf("map valid\n");
	return (true);
}

void get_map_descritpion(t_main *main)
{
	int		i;
	int		j;
	char	**new_map;

	i = 6;
	j = 0;
	new_map = ft_calloc(count_map_height(main->map) - 5, sizeof(char*));
	if (!new_map)
		exit(EXIT_FAILURE);//exit cub3d
	while(main->map[i])
	{
		new_map[j] = ft_strdup(main->map[i++]);
		if (!new_map[j++])
		{
			//free new_map
			exit(EXIT_FAILURE);//exit cub3d
		}
	}
	i = 0;
	while(main->map[i])
		free(main->map[i++]);
	free(main->map);
	main->map = new_map;}
