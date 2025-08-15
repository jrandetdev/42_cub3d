/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_and_colour.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:19:53 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 17:18:06 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	extract_colour_or_texture(t_main *main, char **id_and_info);
static void	check_for_floor_or_ceiling(t_main *main, char *info, char *id);

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
	char	*id;
	char	*info;
	int		id_len;

	id = id_and_info[0];
	info = id_and_info[1];
	id_len = ft_strlen(id);
	if (id_len > 2 || id_len < 1)
	{
		free_string_array(&id_and_info);
		print_error_message(main, "id 2 char max.");
	}
	if (id_len == 2)
		extract_texture(main, id, info);
	else
		check_for_floor_or_ceiling(main, info, id);
}

static void	check_for_floor_or_ceiling(t_main *main, char *info, char *id)
{
	if (xmp_extension_is_valid(info, 3))
	{
		printf("\033[0;33m""Xpm detected for floor or ceiling, \
validating texture...\n""\033[0m");
		assign_floor_ceiling_text(main, id, info);
	}
	else
		extract_colour(main, id, info);
}
