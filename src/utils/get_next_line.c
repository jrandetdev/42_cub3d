/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:05:29 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/18 14:06:17 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_strcpy(char *dest, char *src, int start, int end)
{
	int i = 0;

	while (*src)
	{
		if (i > end)
			break;
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

int	has_new_line(char *buffer)
{
	int i = 0;
	
	while (*buffer)
	{
		if (*buffer == '\n')
			return (i + 1);
		i++;
		buffer++;
	}
	return (0);
}

char	*extract_new_line(char *buffer)
{
	char	*fragment;

	int i = has_new_line(buffer) - 1;
	fragment = (char *)malloc(sizeof(char) * (i + 2));
	ft_strcpy(fragment, buffer, 0, i);
	ft_strcpy(buffer, buffer, i + 1, ft_strlen(buffer) - 1);
	return (fragment);
}

char	*read_until_eol_or_eof(int fd, char *buffer)
{
	int		bytes_read;
	char	*line;
	char	*tmp;
	char	*tmp2;

	line = ft_strdup(buffer);
	while ((bytes_read = read(fd, buffer, BUFFERSIZE)))
	{
		buffer[bytes_read]  = '\0';
		if (has_new_line(buffer))
		{
			tmp = line;
			tmp2 = extract_new_line(buffer);
			line = ft_strjoin(line, tmp2);
			free(tmp);
			free(tmp2);
			return (line);
		}
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
	}
	if (*buffer)
	{
		*buffer = '\0';
		return (line);
	}
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static	char buffer[BUFFERSIZE + 1];

	if (fd < 0 || BUFFERSIZE < 1)
		return (NULL);
	if (has_new_line(buffer))
	{
		return extract_new_line(buffer);
	}
	else
	{
		return read_until_eol_or_eof(fd, buffer);
	}
}
