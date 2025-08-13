/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu_title.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:34 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/13 20:51:08 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_letter_title(t_main *main, char letter)
{
	const char	*path = "Assets/fonts/xpm_80/";
	const char	*white = "_white.xpm";
	char		*first_part;
	char		*filename;

	first_part = ft_charjoin(path, letter);
	if (!first_part)
		print_error_syscall(main, "ft_charjoin failed in \"get_letter_title\"");
	filename = ft_strjoin(first_part, white);
	if (!filename)
	{
		free(first_part);
		print_error_syscall(main, "ft_strjoin failed in \"get_letter_title\"");
	}
	free(first_part);
	return (filename);
}

void	print_menu_title(t_main *main, char *str)
{
	int				x;
	char			*filename;
	t_menu_struct	param;

	x = WIN_WIDTH / 2 - (ft_strlen(str) * 64 / 2);
	param.y = 100;
	while (*str)
	{
		if (*str == ' ')
		{
			x += 64;
			str++;
			continue ;
		}
		filename = get_letter_title(main, *str);
		put_letter(main, &param, filename, x);
		free(filename);
		x += 64;
		str++;
	}
}
