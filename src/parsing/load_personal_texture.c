/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_personal_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:14:09 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:14:13 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_personal_texture(t_main *main, t_texture *pannel, char *filename)
{
	if (!xmp_extension_is_valid(filename, 3))
		print_error_message(main, "Texture file needs xpm extension.");
	get_texture_data(main, pannel, filename);
}
