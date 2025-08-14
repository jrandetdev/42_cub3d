/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:20:06 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 20:16:40 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_len(char *colour);
static bool	is_only_digit(char *colour);
static bool	is_in_char_range(char *s);

bool	is_valid_colour(t_main *main, char **splitted_colours)
{
	int	i;

	i = 0;
	while (splitted_colours[i])
	{
		if (!is_valid_len(splitted_colours[i]))
		{
			free_string_array(&splitted_colours);
			return (false);
		}
		if (!is_only_digit(splitted_colours[i]))
		{
			free_string_array(&splitted_colours);
			print_error_message(main, "Colour contains other characters than digits");
		}
		if (!is_in_char_range(splitted_colours[i]))
		{
			free_string_array(&splitted_colours);
			print_error_message(main, "RGB values must be between 0 - 255");
		}
		i++;
	}
	return (true);
}

static bool	is_valid_len(char *colour)
{
	int	len;

	len = ft_strlen(colour);
	if (1 <= len && len <= 3)
		return (true);
	return (false);
}

static bool	is_only_digit(char *colour)
{
	while (*colour)
	{
		if (!ft_isdigit(*colour))
			return (false);
		colour++;
	}
	return (true);
}

static bool	is_in_char_range(char *s)
{
	if (ft_atoi(s) > 255)
		return (false);
	return (true);
}
