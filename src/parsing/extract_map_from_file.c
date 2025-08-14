/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_from_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:21:10 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 21:50:43 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_map_array(t_main *main, int width, char **file_content);

void	extract_map_from_file(t_main *main, char **file_cont)
{
	t_map *map;

	map = &main->map;
	get_map_dimensions(main, map, file_cont);
	main->map.array = ft_calloc(map->height + 2, sizeof(char *));
	if (!main->map.array)
		print_error_message(main, "Malloc failed in get_map_description.");
	fill_map_array(main, map->width, file_cont);
}

static void	fill_map_array(t_main *main, int width, char **file_content)
{
	int		i;
	int		j;

	i = 6;
	j = 0;
	while (file_content[i])
	{
		main->map.array[j] = max_strdup(file_content[i], width);
		if (!main->map.array[j])
		{
			safe_free_tab((void ***)&main->map.array);
			print_error_message(main, "Max_strdup failed in get_map_des.");
		}
		j++;
		i++;
	}
}
