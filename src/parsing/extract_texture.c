/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:20:40 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/14 11:05:45 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void assign_texture(t_main *main, t_texture *texture, char *file);
static bool	is_available_text_ptr(void *ptr);

void	extract_texture(t_main *main, char *id, char *texture_file)
{
	t_texture_bank	*texture;

	texture = &main->assets.texture_bank;
	if (!xmp_extension_is_valid(texture_file, 3))
		print_error_message(main, "Texture file needs xpm extension.");
	if (!ft_strncmp(id, "NO", 2))
		assign_texture(main, &texture->no, texture_file);
	else if (!ft_strncmp(id, "SO", 2))
		assign_texture(main, &texture->so, texture_file);
	else if (!ft_strncmp(id, "EA", 2))
		assign_texture(main, &texture->ea, texture_file);
	else if (!ft_strncmp(id, "WE", 2))
		assign_texture(main, &texture->we, texture_file);
	else
		print_error_message(main, "Texture id must be NO, SO, EA, or WE");
}

static void assign_texture(t_main *main, t_texture *texture, char *file)
{
	if (is_available_text_ptr(texture->ptr))
		get_texture_data(main, texture, file);
	else
		print_error_message(main, "Direction cannot be used twice");
}

static bool	is_available_text_ptr(void *ptr)
{
	if (!ptr)
		return (true);
	return (false);
}
