/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_dimensions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:36:57 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 22:11:30 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_height(char **file);
static int	get_map_width(char **file_content);

void	get_map_dimensions(t_main *main, t_map *map, char **file_cont)
{
	map->height = get_map_height(file_cont);
	if (map->height > 200)
		print_error_message(main, "Map cannot be more than 200 lines high");
	map->width = get_map_width(file_cont);
	if (map->width > 200)
		print_error_message(main, "Map cannot be more than 200 col wide");
}

static int	get_map_height(char **file)
{
	int	i;

	i = 6;
	while (file[i])
		i++;
	return (i - 6);
}

static int	get_map_width(char **file_content)
{
	size_t	len;
	size_t	max_len;

	max_len = 0;
	file_content += 6;
	while (*file_content)
	{
		len = ft_strlen(*file_content);
		if (len > max_len)
			max_len = len;
		file_content++;
	}
	return (max_len);
}