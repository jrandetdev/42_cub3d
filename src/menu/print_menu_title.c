/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu_title.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:34 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/08 14:06:34 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_letter_filename(t_main *main, char letter)
{
	const char	*path = "Assets/fonts/xpm_80/";
	const char	*white = "_white.xpm";
	char		*first_part;
	char		*filename;

	first_part = ft_charjoin(path, letter);
	if (!first_part)
		exit_cub3d(main, "'get_letter' malloc falied");
	filename = ft_strjoin(first_part, white);
	if (!filename)
	{
		free(first_part);
		exit_cub3d(main, "'get_letter' malloc falied");
	}
	free(first_part);
	return (filename);
}

void	print_menu_title(t_main *main, char *str)
{
	int				x;
	static int		y = 100;
	char			*filename;
	t_texture		letter;

	x = main->cal.half_ww - (ft_strlen(str) * 64 / 2);
	while (*str)
	{
		if (*str == ' ')
		{
			x += 64;
			str++;
			continue ;
		}
		filename = get_letter_filename(main, ft_capitalize(*str));
		letter.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, filename,
				&letter.width, &letter.height);
		free(filename);
		if (!letter.texture_ptr)
			exit_cub3d(main, "failed to load a letter int 'print_menu_title'");
		mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
			letter.texture_ptr, x, y);
		mlx_destroy_image(main->mlx_ptr, letter.texture_ptr);
		x += 64;
		str++;
	}
}
