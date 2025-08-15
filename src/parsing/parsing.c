/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:21:06 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 18:46:58 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_main *main, char *file)
{
	t_parsing	*parsing;

	parsing = &main->parsing;
	check_if_file_is_dir(main, file);
	extract_file_elements(main, file, &parsing->file_content);
	extract_colour_and_texture(main, parsing->file_content);
	extract_map_from_file(main, parsing->file_content);
	free_string_array(&parsing->file_content);
	check_if_map_is_valid(main);
}
