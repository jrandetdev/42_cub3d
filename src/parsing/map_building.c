/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:11:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/18 16:46:03 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool is_only_spaces(char *line)
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

static void	null_terminate_line(char **line)
{
	char	*cursor;

	cursor = *line;
	while (*cursor && *cursor != '\n')
		cursor++;
	*cursor = '\0';
}

static void	count_lines(char *file, int *line_counter)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			print_error_and_message("EOF is reached.\n");
			break ;
		}
		if (!is_only_spaces(line))
			(*line_counter)++;
		free(line);
	}
	close (fd);
}

char	**build_map(int fd, char *file)
{
	int		line_counter;
	char	**map;
	char	*line;
	int		i;

	line_counter = 0;
	count_lines(file, &line_counter);
	printf("line counter is worth %d\n", line_counter);
	map = ft_calloc(line_counter + 1, sizeof(char *));
	if (!map)
	{
		print_error_and_message("Malloc Error\n");
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		null_terminate_line(&line);
		if (!is_only_spaces(line))
		{
			map[i] = ft_strdup(line);
			if (!map[i])
			{
				free(line);
				free_string_array(&map);
				return (NULL);
			}
			i++;
		}
		free(line);
	}
	map[i] = NULL;
	print_array(map);
	return (map);
}
