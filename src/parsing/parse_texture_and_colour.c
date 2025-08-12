/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_and_colour.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:19:53 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/12 16:33:07 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void check_tabs(t_main *main, char **file_content)
{
	int	i;
	int	j;

	j = 0;
	while (file_content[j])
	{
		i = 0;
		while (file_content[j][i])
		{
			if (file_content[j][i] == '\t')
			{
				free_string_array(&file_content);
				print_error_message(main, "the program does not accepts tabs");
			}
			i++;
		}
		j++;
	}
}

static void	extract_colour_or_texture(t_main *main)
{
	char	*identifier;
	char	*information;
	int		id_len;

	identifier = main->id_and_info[0];
	information = main->id_and_info[1];
	id_len = ft_strlen(identifier);
	if (id_len > 2 || id_len < 1)
		print_error_message(main, "Identifier 2 char max.");
	if (id_len == 2)
		extract_texture(main, identifier, information);
	else
		extract_colour(main, identifier, information);
}

void	parse_map_elements(t_main *main, char **file_content)
{
	int		i;

	i = 0;
	check_tabs(main, file_content);
	while (i <= 5)
	{
		main->id_and_info = ft_split(file_content[i], ' ');
		if (!main->id_and_info)
			print_error_syscall(main, "Ft_split failed in texture function.");
		if (string_array_len(main->id_and_info) != 2)
			print_error_message(main, "Incorrect texture or colour format.");
		extract_colour_or_texture(main);
		free_string_array(&main->id_and_info);
		i++;
	}
}
