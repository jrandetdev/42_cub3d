/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu_section.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:39 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/26 21:43:15 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_letter_filename(t_main *main, char letter, int i, int selected)
{
	const char	*path = "Assets/fonts/xpm_48/";
	const char	*white = "_white.xpm";
	const char	*gold = "_gold.xpm";
	char		*first_part;
	char		*filename;

	first_part = ft_charjoin(path, letter);
	if (!first_part)
		exit_cub3d(main, "'get_letter' malloc falied");
	if (selected == i)
		filename = ft_strjoin(first_part, gold);
	else
		filename = ft_strjoin(first_part, white);
	if (!filename)
	{
		free(first_part);
		exit_cub3d(main, "'get_letter' malloc falied");
	}
	free(first_part);
	return (filename);
}

void	print_menu_section_3(t_main *main, int selection, int i, char *str)
{
	int				x;
	static int		y = WIN_HEIGHT / 2 - 3 * 48 + 48;
	char			*filename;
	t_texture		letter;

	x = main->cal.half_ww - (ft_strlen(str) * 48 / 2);
	while (*str)
	{
		filename = get_letter_filename(main, ft_capitalize(*str), i, selection);
		letter.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, filename,
				&letter.width, &letter.height);
		free(filename);
		if (!letter.texture_ptr)
			exit_cub3d(main, "failed to load a letter int 'print_menu_title'");
		mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
			letter.texture_ptr, x, y);
		x += 48;
		str++;
		mlx_destroy_image(main->mlx_ptr, letter.texture_ptr);
	}
	y += 64;
	if (i == 2)
		y = main->cal.half_wh - 3 * 48 + 48;
}

void	print_menu_section_4(t_main *main, int selection, int i, char *str)
{
	int				x;
	static int		y = WIN_HEIGHT / 2 - 3 * 48 + 48;
	char			*filename;
	t_texture		letter;

	x = main->cal.half_ww - (ft_strlen(str) * 48 / 2);
	while (*str)
	{
		filename = get_letter_filename(main, ft_capitalize(*str), i, selection);
		letter.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, filename,
				&letter.width, &letter.height);
		free(filename);
		if (!letter.texture_ptr)
			exit_cub3d(main, "failed to load a letter int 'print_menu_title'");
		mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
			letter.texture_ptr, x, y);
		x += 48;
		str++;
		mlx_destroy_image(main->mlx_ptr, letter.texture_ptr);
	}
	y += 64;
	if (i == 3)
		y = main->cal.half_wh - 3 * 48 + 48;
}
