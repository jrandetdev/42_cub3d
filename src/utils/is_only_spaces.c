/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:22:31 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:37:58 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_only_space(char *line)
{
	while (*line)
	{
		if ((9 <= *line && *line <= 13) || *line == ' ')
			line++;
		else
			return (false);
	}
	return (true);
}
