/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_desription.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:10:09 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/24 16:58:43 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_map_height(char **file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	return (i);
}

static size_t	get_max_row_size(char **file_content)
{
	size_t	len;
	size_t	max_len;

	max_len = 0;
	while(*file_content)
	{
		len = ft_strlen(*file_content);
		if (len > max_len)
			max_len = len;
		file_content++;
	}
	return (max_len);
}

static char *max_strdup(const char *s1, int max_size)
{

	char	*pointer;
	size_t	len;

	if (*s1 == '\0')
		return (ft_calloc(1, 1));
	len = ft_strlen(s1);
	pointer = ft_calloc(max_size, sizeof(char));
	if (!pointer)
		return (NULL);
	ft_memcpy(pointer, s1, len + 1);
	return (pointer);
}

void	get_map_descritpion(t_main *main, char **file_content)
{
	int		i;
	int		j;

	i = 6;
	j = 0;
	main->map_struct.height = count_map_height(file_content) - 5;
	main->map_struct.width = get_max_row_size(file_content);
	main->map_struct.map = ft_calloc(main->map_struct.height, sizeof(char *));
	if (!main->map_struct.map)
		exit_cub3d(main, EXIT_FAILURE);
	while (file_content[i])
	{
		main->map_struct.map[j] = max_strdup(file_content[i], main->map_struct.width);
		if (!main->map_struct.map[j])
		{
			safe_free_tab((void ***)&main->map_struct.map);
			exit_cub3d(main, EXIT_FAILURE);
		}
		j++;
		i++;
	}
	main->map_struct.height = count_map_height(main->map_struct.map);
	main->map_struct.width = get_max_row_size(main->map_struct.map);
}
