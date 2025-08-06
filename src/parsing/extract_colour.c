/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:10:27 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/06 15:33:29 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assign_colour(t_colour *pannel, char **rgb_colours)
{
	pannel->b = ft_atoi(rgb_colours[0]);
	pannel->g = ft_atoi(rgb_colours[1]);
	pannel->r = ft_atoi(rgb_colours[2]);
	free_string_array(&rgb_colours);
	pannel->is_texture = 0;
}

void	extract_colour(t_main *main, char *id, char *info)
{
	char	**rgb_colours;

	if (!(ft_strncmp(id, "F", 1) == 0))
	{
		if (!(ft_strncmp(id, "C", 1) == 0))
			return (exit_cub3d(main, "Colour: please use F and C."));
	}
	rgb_colours = ft_split(info, ',');
	if (!rgb_colours)
		return (exit_cub3d(main, "Ft_split failed in extract_fc_colours."));
	if (!validate_colour(main, rgb_colours))
	{
		if (ft_strncmp(id, "F", 1) == 0)
			main->f_colour.is_texture = 1;
		else
			main->c_colour.is_texture = 1;
		return ;
	}
	if (ft_strncmp(id, "F", 1) == 0)
		return (assign_colour(&main->f_colour, rgb_colours));
	return (assign_colour(&main->c_colour, rgb_colours));
}
