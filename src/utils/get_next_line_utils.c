/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:24:57 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/25 11:30:12 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_strcpy(char *dest, char *src, int start, int end)
{
	int	i;

	i = 0;
	while (*src)
	{
		if (i > end)
			break ;
		if (i >= start)
		{
			*dest = *src;
			dest++;
		}
		i++;
		src++;
	}
	*dest = '\0';
}

char	*join_and_free(char *line, char *tmp2)
{
	char	*tmp;
	char	*new_line;

	tmp = line;
	new_line = ft_strjoin(line, tmp2);
	free(tmp);
	free(tmp2);
	return (new_line);
}

int	has_new_line(char *buffer)
{
	int	i;

	i = 0;
	while (*buffer)
	{
		if (*buffer == '\n')
			return (i + 1);
		i++;
		buffer++;
	}
	return (0);
}
