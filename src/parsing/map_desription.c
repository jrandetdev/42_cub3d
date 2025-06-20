/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_desription.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:10:09 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/20 10:28:09 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
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
