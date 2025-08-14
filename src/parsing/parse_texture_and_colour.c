/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_and_colour.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:19:53 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 23:05:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	extract_colour_or_texture(t_main *main, char **id_and_info);

void	extract_colour_and_texture(t_main *main, char **file_content)
{
	int		i;
	char	**id_and_info;

	i = 0;
	while (i <= 5)
	{
		id_and_info = ft_split(file_content[i], ' ');
		if (!id_and_info)
			print_error_syscall(main, "Ft_split failed in texture function.");
		if (string_array_len(id_and_info) != 2)
		{
			free_string_array(&id_and_info);
			print_error_message(main, "Incorrect texture or colour format.");
		}
		extract_colour_or_texture(main, id_and_info);
		free_string_array(&id_and_info);
		i++;
	}
}

static void	extract_colour_or_texture(t_main *main, char **id_and_info)
{
	char	*identifier;
	char	*information;
	int		id_len;
	

	identifier = id_and_info[0];
	information = id_and_info[1];
	id_len = ft_strlen(identifier);
	if (id_len > 2 || id_len < 1)
	{
		free_string_array(&id_and_info);
		print_error_message(main, "Identifier 2 char max.");
	}
	if (id_len == 2)
		extract_texture(main, identifier, information);
	else
		extract_colour(main, identifier, information);
}

