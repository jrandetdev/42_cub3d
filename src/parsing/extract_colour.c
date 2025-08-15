/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:10:27 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:12:09 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assign_colour(t_main *main, char *id, char **colours);
void		assign_floor_ceiling_text(t_main *main, char *id, char *filename);
static void	fill_colour(t_main *main, t_colour *pannel, char **colours);

void	extract_colour(t_main *main, char *id, char *info)
{
	char	**colours;

	if (ft_strncmp(id, "F", 1) && ft_strncmp(id, "C", 1))
		print_error_message(main, "Colour: please use F and C.");
	colours = ft_split(info, ',');
	if (!colours)
		print_error_syscall(main, "Ft_split failed in extract_fc_colours");
	if (is_valid_colour(main, colours))
		assign_colour(main, id, colours);
	else
		assign_floor_ceiling_text(main, id, info);
}

static void	assign_colour(t_main *main, char *id, char **colours)
{
	if (ft_strncmp(id, "F", 1) == 0)
		fill_colour(main, &main->assets.f_colour, colours);
	else
		fill_colour(main, &main->assets.c_colour, colours);
}

void	assign_floor_ceiling_text(t_main *main, char *id, char *filename)
{
	t_texture_bank	*texture;

	texture = &main->assets.texture_bank;
	if (ft_strncmp(id, "F", 1) == 0)
		load_personal_texture(main, &texture->floor, filename);
	else
		load_personal_texture(main, &texture->ceiling, filename);
}

static void	fill_colour(t_main *main, t_colour *pannel, char **colours)
{
	if (!colours[0] || !colours[1] || !colours[2])
	{
		free_string_array(&colours);
		print_error_message(main, "Incorrect RGB colour format");
	}
	pannel->b = ft_atoi(colours[0]);
	pannel->g = ft_atoi(colours[1]);
	pannel->r = ft_atoi(colours[2]);
	free_string_array(&colours);
}
