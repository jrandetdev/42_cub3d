/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_desription.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:10:09 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/19 15:52:11 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	flood_fill(char **map, int player, int x, int y)
{
	
}

static size_t	count_map_height(char **map)
{
	int	i;

	i = 0;
	while(map[i])
		i++;
	printf("%d\n", i);
	return (i - 5);
}

void get_map_descritpion(t_main *main)
{
	int		i;
	int		j;
	char	**new_map;

	i = 6;
	j = 0;
	new_map = ft_calloc(count_map_height(main->map), sizeof(char*));
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
	main->map = new_map;
	print_array(main->map);
}
