/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu_section.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:39 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/27 21:59:53 by hdougoud         ###   ########.fr       */
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

void	print_menu_section(t_main *main, t_menu_struct *param, char *str)
{
	int				x;
	char			*filename;
	t_texture		letter;

	x = main->cal.half_ww - (ft_strlen(str) * 48 / 2);
	while (*str)
	{
		filename = get_letter_filename(main, ft_capitalize(*str), param->idx, param->selection);
		letter.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, filename,
				&letter.width, &letter.height);
		free(filename);
		if (!letter.texture_ptr)
			exit_cub3d(main, "failed to load a letter int 'print_menu_title'");
		mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
			letter.texture_ptr, x, param->y);
		x += 48;
		str++;
		mlx_destroy_image(main->mlx_ptr, letter.texture_ptr);
	}
	param->y += 64;
	param->idx++;
}

void	print_case(t_main *main, t_menu_struct *menu, int param, char *str)
{
	int			x;
	char	*empty_case = "Assets/fonts/xpm_48/epmty_case_white.xpm";
	char	*full_case = "Assets/fonts/xpm_48/cross_case_white.xpm";
	t_texture	cross;

	x = main->cal.half_ww + 4 * 48;
	if (param)
	{
		cross.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, full_case, &cross.width, &cross.height);
		if (!cross.texture_ptr)
			exit_cub3d(main, "failed to load case logo");
		mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, cross.texture_ptr, x, menu->y);
	}
	else
	{
		cross.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, empty_case, &cross.width, &cross.height);
		if (!cross.texture_ptr)
			exit_cub3d(main, "failed to load case logo");
		mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, cross.texture_ptr, x, menu->y);
	}
	print_menu_section(main, menu, str);
}
