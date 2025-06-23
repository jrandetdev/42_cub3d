/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_desription.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:10:09 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/23 14:09:29 by jrandet          ###   ########.fr       */
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

static size_t	get_max_row_size(char **map)
{
	size_t	len;
	size_t	max_len;

	max_len = 0;
	while(*map)
	{
		len = ft_strlen(*map);
		if (len > max_len)
			max_len = len;
		map++;
	}
	printf("%ld\n", max_len);
	return (max_len + 1);
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

void	get_map_descritpion(t_main *main)
{
	int		i;
	int		j;
	char	**new_map;

	i = 6;
	j = 0;
	main->map_struct.height = count_map_height(main->map_struct.map) - 5;
	new_map = ft_calloc(main->map_struct.height, sizeof(char *));
	if (!new_map)
		exit_cub3d(main, EXIT_FAILURE);
	main->map_struct.width = get_max_row_size(main->map_struct.map);
	while (main->map_struct.map[i])
	{
		new_map[j] = max_strdup(main->map_struct.map[i++], main->map_struct.width);
		if (!new_map[j++])
		{
			safe_free_tab((void ***)&new_map);
			exit_cub3d(main, EXIT_FAILURE);
		}
	}
	i = 0;
	//safe_free_tab((void ***)&main->map_struct.map);
	//free_string_array(&main->map_struct.map);
	main->map_struct.map = new_map;
	printf("GOT HERE\n");
}
