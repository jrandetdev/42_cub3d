/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:13:43 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 19:22:59 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	prepare_file_buffer(t_main *main, char *file, char ***fc);
static void	count_file_lines(t_main *main, char *file, int *line_counter);
static void	open_and_fill_buffer(t_main *main, char *file, char ***fc);
static bool	fill_buffer(char ***fc, int fd);

void	extract_file_elements(t_main *main, char *file, char ***fc)
{
	prepare_file_buffer(main, file, fc);
	open_and_fill_buffer(main, file, fc);
	check_for_tabs(main, *fc);
}

static void	prepare_file_buffer(t_main *main, char *file, char ***fc)
{
	int		line_counter;

	count_file_lines(main, file, &line_counter);
	if (line_counter == 0)
		print_error_message(main, "File is empty.");
	if (line_counter <= 6)
		print_error_message(main, "No map description.");
	*fc = ft_calloc(line_counter + 1, sizeof(char *));
	if (!(*fc))
		print_error_syscall(main, "Malloc failed in extract_file_elements.");
}

static void	count_file_lines(t_main *main, char *file, int *line_counter)
{
	int		fd;
	char	*line;

	fd = get_fd(main, file);
	*line_counter = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break ;
		}
		if (*line_counter > 5 && is_only_space(line))
			(*line_counter)++;
		else if (!is_only_space(line))
			(*line_counter)++;
		free(line);
	}
	close (fd);
}

static void	open_and_fill_buffer(t_main *main, char *file, char ***fc)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free_string_array(fc);
		print_error_syscall(main, "Open failed in extract_file_elements");
	}
	if (!fill_buffer(fc, fd))
	{
		close(fd);
		free_string_array(fc);
		print_error_syscall(main, "Malloc failed in fill parse buffer.");
	}
	close(fd);
}

static bool	fill_buffer(char ***fc, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		null_terminate_line(&line);
		if (!is_only_space(line) || (i > 5 && is_only_space(line)))
		{
			(*fc)[i] = ft_strdup(line);
			if (!(*fc)[i])
			{
				free(line);
				free_string_array(fc);
				return (false);
			}
			i++;
		}
		free(line);
	}
	return (true);
}
