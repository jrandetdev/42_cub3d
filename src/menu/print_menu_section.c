/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu_section.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:39 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/13 23:55:25 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_letter(t_main *main, char letter, int i, int selected)
{
	const char	*path = "Assets/fonts/xpm_48/";
	const char	*white = "_white.xpm";
	const char	*gold = "_gold.xpm";
	char		*first_part;
	char		*filename;

	first_part = ft_charjoin(path, letter);
	if (!first_part)
		print_error_syscall(main, "ft_charjoin failed in \"get_letter\"");
	if (selected == i)
		filename = ft_strjoin(first_part, gold);
	else
		filename = ft_strjoin(first_part, white);
	if (!filename)
	{
		free(first_part);
		print_error_syscall(main, "ft_strjoin failed in \"get_letter\"");
	}
	free(first_part);
	return (filename);
}

void	print_menu_section(t_main *main, t_menu_struct *param, char *str)
{
	int				x;
	char			*filename;

	x = WIN_WIDTH / 2 - (ft_strlen(str) * 48 / 2);
	while (*str)
	{
		if (*str == ' ')
		{
			str++;
			x += 64;
			continue ;
		}
		filename = get_letter(main, *str, param->idx, param->selection);
		put_letter(main, param, filename, x);
		free(filename);
		x += 48;
		str++;
	}
	param->y += 64;
	param->idx++;
}

void	print_box(t_main *main, t_menu_struct *menu, int param, char *str)
{
	int			x;
	char		*filename;
	t_texture	cross;

	x = WIN_WIDTH / 2 + 7 * 48;
	if (param)
		filename = "Assets/fonts/logo/checked_box_white.xpm";
	else
		filename = "Assets/fonts/logo/empty_box_white.xpm";
	cross.ptr = mlx_xpm_file_to_image(main->mlx_ptr, filename,
			&cross.width, &cross.height);
	if (!cross.ptr)
		print_error_syscall(main, "mlx_xpm_file_to_image failed in print_box");
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
		cross.ptr, x, menu->y);
	mlx_destroy_image(main->mlx_ptr, cross.ptr);
	print_menu_section(main, menu, str);
}
