/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_desription.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:21:10 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/05 14:42:14 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_map_height(char **file)
{
	int	i;

	i = 6;
	while (file[i])
		i++;
	return (i - 6);
}

static size_t	get_max_row_size(char **file_content)
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

char	*max_strdup(const char *s1, int max_size)
{
	char	*pointer;
	size_t	len;

	if (*s1 == '\0')
		return (ft_calloc(1, 1));
	len = ft_strlen(s1);
	pointer = ft_calloc(max_size + 1, sizeof(char));
	if (!pointer)
		return (NULL);
	ft_memcpy(pointer, s1, len + 1);
	return (pointer);
}

void	fill_map(t_main *main, int width)
{
	int		i;
	int		j;

	i = 6;
	j = 0;
	while (main->file_content[i])
	{
		main->map_struct.map[j] = max_strdup(main->file_content[i], width);
		if (!main->map_struct.map[j])
		{
			safe_free_tab((void ***)&main->map_struct.map);
			return (exit_cub3d(main, "Max_strdup failed in get_map_des."));
		}
		j++;
		i++;
	}
}

void	get_map_descritpion(t_main *main)
{
	int		height;
	int		width;

	height = count_map_height(main->file_content);
	width = get_max_row_size(main->file_content);
	if (height > 200 || width > 200)
		exit_cub3d(main, "Map is too big.");
	main->map_struct.map = ft_calloc(height + 2, sizeof(char *));
	if (!main->map_struct.map)
		return (exit_cub3d(main, "Malloc failed in get_map_description."));
	fill_map(main, width);
	main->map_struct.width = width;
	main->map_struct.height = height;
}
