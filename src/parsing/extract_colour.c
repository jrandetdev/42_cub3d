/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:10:27 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/12 17:21:48 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_ceiling_texture(t_main *main, char *filename)
{
	printf(YELLOW"Incorrect color format for ceiling... "
		"Trying to load texture\n"RESET);
	check_and_get_texture(main, &main->assets.texture_bank.ceiling, filename);
}

static void	load_floor_texture(t_main *main, char *filename)
{
	printf(YELLOW"Incorrect color format for floor... "
		"Trying to load texture\n"RESET);
	check_and_get_texture(main, &main->assets.texture_bank.floor, filename);
}

static void	assign_colour(t_main *main, t_colour *pannel, char **rgb_colours)
{
	if (!rgb_colours[0] || !rgb_colours[1] || !rgb_colours[2])
	{
		free_string_array(&rgb_colours);
		print_error_message(main, "Incorrect RGB colour format");
	}
	pannel->b = ft_atoi(rgb_colours[0]);
	pannel->g = ft_atoi(rgb_colours[1]);
	pannel->r = ft_atoi(rgb_colours[2]);
	free_string_array(&rgb_colours);
}

void	extract_colour(t_main *main, char *id, char *info)
{
	char	**rgb_colours;

	if (!(ft_strncmp(id, "F", 1) == 0))
	{
		if (!(ft_strncmp(id, "C", 1) == 0))
			print_error_message(main, "Colour: please use F and C.");
	}
	rgb_colours = ft_split(info, ',');
	if (!rgb_colours)
		print_error_syscall(main, "Ft_split failed in extract_fc_colours");
	if (!validate_colour(main, rgb_colours))
	{
		if (ft_strncmp(id, "F", 1) == 0)
			load_floor_texture(main, info);
		else
			load_ceiling_texture(main, info);
		return ;
	}
	if (ft_strncmp(id, "F", 1) == 0)
		return (assign_colour(main, &main->assets.f_colour, rgb_colours));
	return (assign_colour(main, &main->assets.c_colour, rgb_colours));
}
