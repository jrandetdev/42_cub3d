/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:29:38 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 13:33:38 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**copy_map(t_map *map)
{
	int			i;
	int			j;
	char		**new_map;

	i = 0;
	j = 0;
	new_map = ft_calloc(map->height + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	while (map->array[i])
	{
		new_map[j] = max_strdup(map->array[i++], map->width);
		if (!new_map[j])
		{
			safe_free_tab((void ***)&new_map);
			return (NULL);
		}
		j++;
	}
	return (new_map);
}
