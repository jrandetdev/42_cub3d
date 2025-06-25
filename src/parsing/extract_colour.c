/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:10:27 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/25 17:59:07 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	assign_floor_or_ceiling_colour(t_colour *pannel, char **colours)
{
	pannel->r = ft_atoi(colours[0]);
	pannel->g = ft_atoi(colours[1]);
	pannel->b = ft_atoi(colours[2]);
	free_string_array(&colours);
	return (true);
}

bool	extract_fc_colour(t_main *main, char *id, char *colours_info)
{
	char	**splitted_colours;

	splitted_colours = ft_split(colours_info, ',');
	if (!splitted_colours)
		return (false);
	print_array(splitted_colours);
	if (!(ft_strncmp(id, "F", 1) == 0))
	{
		if (!(ft_strncmp(id, "C", 1) == 0))
		{
			print_error_and_message("Floor or Ceiling: please use id F or C\n");
			return (false);
		}
	}
	if (!is_valid_colours(main, splitted_colours))
		return (false);
	if (ft_strncmp(id, "F", 1) == 0)
		return (assign_floor_or_ceiling_colour(&main->f_colour, splitted_colours));
	return (assign_floor_or_ceiling_colour(&main->c_colour, splitted_colours));
}
