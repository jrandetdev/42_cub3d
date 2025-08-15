/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_tabs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:56:46 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:13:00 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_for_tabs(t_main *main, char **file_content)
{
	int	i;
	int	j;

	j = 0;
	while (file_content[j])
	{
		i = 0;
		while (file_content[j][i])
		{
			if (file_content[j][i] == '\t')
			{
				free_string_array(&file_content);
				print_error_message(main, "the program does not accepts tabs");
			}
			i++;
		}
		j++;
	}
}
