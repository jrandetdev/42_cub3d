/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_and_colour.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:19:53 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/23 12:56:49 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	extract_colour_or_texture(t_main *main)
{
	char	*identifier;
	char	*information;
	int		id_len;

	identifier = main->id_and_info[0];
	information = main->id_and_info[1];
	id_len = ft_strlen(identifier);
	if (id_len > 2 || id_len < 1)
		return (exit_cub3d(main, "Identifier 2 char max."));
	if (id_len == 2)
		extract_texture(main, identifier, information);
	else
		extract_colour(main, identifier, information);
}

void	parse_map_elements(t_main *main)
{
	int		i;

	i = 0;
	while (i <= 5)
	{
		main->id_and_info = ft_split(main->file_content[i], ' ');
		if (!main->id_and_info)
			return (exit_cub3d(main, "Ft_split failed in texture function."));
		if (string_array_len(main->id_and_info) != 2)
			return (exit_cub3d(main, "Incorrect texture or colour format."));
		extract_colour_or_texture(main);
		free_string_array(&main->id_and_info);
		i++;
	}
}
