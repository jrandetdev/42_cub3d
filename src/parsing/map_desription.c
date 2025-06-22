/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_desription.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:10:09 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/23 00:15:06 by jrandet          ###   ########.fr       */
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
	return (max_len);
}

void	get_map_descritpion(t_main *main)
{
	int		i;
	int		j;
	int		max_len;
	char	**new_map;

	i = 6;
	j = 0;
	new_map = ft_calloc(count_map_height(main->map) - 5, sizeof(char *));
	if (!new_map)
		exit_cub3d(main, EXIT_FAILURE);
	max_len = get_max_row_size(main->map);
	while (main->map[i])
	{
		new_map[j] = max_strdup(main->map[i++], max_len);
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
