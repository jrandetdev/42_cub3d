/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_and_texture.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:10:38 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/23 18:27:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	extract_texture(char *identifier, char *info)
{
	int fd;

	
	if (ft_strcmp(identifier, "NO") == 0)
		mlx_xpm_to_image()
	else if (ft_strcmp(identifier, "SO") == 0)
		
	else if (ft_strcmp(identifier, "WE") == 0)
		
	else if (ft_strcmp(identifier, "EA") == 0)
		
}

static bool	parse_texture_or_colour(char **splitted_elements)
{
	char	*identifier;
	char	*information;
	int		id_len;
	int		info_len;

	if (splitted_elements[1] == NULL)
		return (false);
	identifier = splitted_elements[0];
	information = splitted_elements[1];
	id_len = ft_strlen(identifier);
	if (id_len > 2 || id_len < 1)
		return (false);
	if (id_len == 2)
		extract_texture(identifier, information);
	else
		extract_floor_or_ceiling(identifier, information);
}

void	extract_info_array(t_main *main, char **file)
{
	int		i;
	char	**splitted_elements;

	i = 0;
	while (i <= 5)
	{
		splitted_elements = ft_split(&file[i], ' ');
		if (!splitted_elements)
			exit_cub3d(main, 1);
		if (string_array_len(splitted_elements) != 2)
		{
			free_string_array(&splitted_elements);
			exit_cub3d(main, 1);
		}	
		if (!parse_texture_or_colour(splitted_elements))
		{
			free_string_array(&splitted_elements);
			exit_cub3d(main, 1);
		}
		i++;
	}
}