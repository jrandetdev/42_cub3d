/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_desription.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:10:09 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/19 18:06:57 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	count_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	flood_fill(char **map, int *player, int x, int y, int *valid)
{
	if (*valid == 0)
		return ;
	if (x < 0 || y < 0 || map[y][x] == '\0' || map[y][x] == ' ')
	{
		*(valid) = 0;
		return ;
	}
	if (map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
		*(player) += 1;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, player, x + 1, y, valid);
	flood_fill(map, player, x, y + 1, valid);
	flood_fill(map, player, x - 1, y, valid);
	flood_fill(map, player, x, y - 1, valid);
	//corner not be good
	//dont work if we have 2 player and one is isolated
}

static char	**copy_map(char **map, char **new_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	new_map = ft_calloc(count_map_height(map) + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		new_map[j++] = ft_strdup(map[i++]);
		if (!new_map)
		{
			safe_free_tab((void ***)&new_map);
			return (NULL);
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
	if (!reviewed_map)
		return (false);
	flood_fill(reviewed_map, &player, 4, 10, &valid);
	if (player != 1)
	{
		printf("wrong player number %d\n", player);
		return (false);
	}
	if (!valid)
	{
		printf("wrong patern %d\n", valid);
		return (false);
	}
	printf("map valid\n");
	return (true);
}

void	get_map_descritpion(t_main *main)
{
	int		i;
	int		j;
	char	**new_map;

	i = 6;
	j = 0;
	new_map = ft_calloc(count_map_height(main->map) - 5, sizeof(char *));
	if (!new_map)
		exit_cub3d(main, EXIT_FAILURE);
	while (main->map[i])
	{
		new_map[j] = ft_strdup(main->map[i++]);
		if (!new_map[j++])
		{
			safe_free_tab((void ***)&new_map);
			exit_cub3d(main, EXIT_FAILURE);
		}
	}
	i = 0;
	safe_free_tab((void ***)&main->map);
	main->map = new_map;
}
