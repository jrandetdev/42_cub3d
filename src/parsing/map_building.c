/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:11:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/23 11:15:55 by jrandet          ###   ########.fr       */
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

void	fill_map(t_main *main, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		null_terminate_line(&line);
		if (!is_only_spaces(line))
		{
			main->map_struct.map[i] = ft_strdup(line);
			if (!main->map_struct.map[i])
			{
				free(line);
				exit_cub3d(main, 1);
			}
			i++;
		}
		free(line);
	}
 
}

static void	count_lines(char *file, int *line_counter)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	*line_counter = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			//print_error_and_message("EOF is reached.\n");
			break ;
		}
		if (!is_only_spaces(line))
			(*line_counter)++;
		free(line);
	}
	close (fd);
}

void	build_map(t_main *main, int fd, char *file)
{
	int		line_counter;

	count_lines(file, &line_counter);
	main->map_struct.map = ft_calloc(line_counter + 1, sizeof(char *));
	if (!main->map_struct.map)
		exit_cub3d(main, 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_cub3d(main, 1);
	fill_map(main, fd);
	close(fd);
}
