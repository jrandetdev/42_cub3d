/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:47 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/14 11:05:45 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	selection(t_main *main, int *menu, int selection, int *menu_title)
{
	main->interaction.keys.enter = 0;
	if (selection == 0 && main->interaction.mouse.sensitivity < MAX_SENSITIVITY - 50)
		main->interaction.mouse.sensitivity += 1;
	else if (selection == 1 && main->interaction.mouse.sensitivity > MIN_SENSITIVITY)
		main->interaction.mouse.sensitivity -= 1;
	else if (selection == 2)
	{
		*(menu_title) = 0;
		if (!main->game_start)
			*(menu) = MAIN_MENU;
		else
			*menu = OPTION_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
}

static void	print_current_sensitivity(t_main *main, int last_y)
{
	char			*sensitvity;
	char			*menu_name;
	t_menu_struct	param;

	ft_bzero(&param, sizeof(t_menu_struct));
	param.y = last_y - 300;
	param.idx = 1;
	sensitvity = ft_itoa(main->interaction.mouse.sensitivity);
	if (!sensitvity)
		print_error_syscall(main, "malloc failed in print current seinsitvity");
	if (main->interaction.mouse.sensitivity >= 10)
		menu_name = ft_strjoin("CURRENT SENSITIVTY ", sensitvity);
	else
		menu_name = ft_strjoin("CURRENT SENSITIVTY 0", sensitvity);
	free(sensitvity);
	if (!menu_name)
		print_error_syscall(main, "malloc failed in print current seinsitvity");
	print_menu_section(main, &param, menu_name);
	free(menu_name);
}

static void	print_minus_logo(t_main *main, int selection, int last_y)
{
	t_texture	logo;
	char		*filename;

	if (selection == 1)
		filename = "assets/fonts/logo/minus_gold.xpm";
	else
		filename = "assets/fonts/logo/minus_white.xpm";
	logo.ptr = mlx_xpm_file_to_image(main->mlx_ptr, filename,
			&logo.width, &logo.height);

	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, logo.ptr,
		WIN_WIDTH / 2 + 50, last_y - 200);
	mlx_destroy_image(main->mlx_ptr, logo.ptr);
}

static void	print_plus_logo(t_main *main, int selection, int last_y)
{
	t_texture	logo;
	char		*filename;

	if (selection == 0)
		filename = "assets/fonts/logo/plus_gold.xpm";
	else
		filename = "assets/fonts/logo/plus_white.xpm";
	logo.ptr = mlx_xpm_file_to_image(main->mlx_ptr, filename,
			&logo.width, &logo.height);
	if (!logo.ptr)
		print_error_syscall(main, "mlx load image failed in print minus logo");
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, logo.ptr,
		WIN_WIDTH / 2 + 50 - 228, last_y - 200);
	mlx_destroy_image(main->mlx_ptr, logo.ptr);
}

void	show_mouse_sensitivity_menu(t_main *main, int *menu)
{
	t_menu_struct	param;
	static int		menu_title = 0;

	ft_bzero(&param, (sizeof(t_menu_struct)));
	param.menu_size = 3;
	if (menu_title < 0)
		menu_title = 2;
	param.y = WIN_HEIGHT / 2 + WIN_HEIGHT / 5;
	param.selection = (menu_title % param.menu_size);
	print_menu_title(main, "MOUSE SENSITIVITY");
	print_current_sensitivity(main, param.y);
	print_minus_logo(main, param.selection, param.y);
	print_plus_logo(main, param.selection, param.y);
	param.idx = 2;
	print_menu_section(main, &param, "RETURN");
	if (main->interaction.keys.enter)
		selection(main, menu, param.selection, &menu_title);
	else if (main->interaction.keys.up || main->interaction.keys.down)
		menu_up_and_down(main, &menu_title);
}
