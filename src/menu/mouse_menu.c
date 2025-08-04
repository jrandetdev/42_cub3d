/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:47 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/04 08:56:37 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	apply_selection(t_main *main, int *menu, int selection, int *menu_title)
{
	main->keys.enter = 0;
	if (selection == 0)
	{
		
	}
	else if (selection == 1)
	{
		*(menu_title) = 0;
		if (!main->game_start)
			*(menu) = MAIN_MENU;
		else
			*menu = PAUSE_MENU;
		mlx_clear_window(main->mlx_ptr, main->mlx_win);
	}
}

static void	print_current_sensitivity(t_main *main)
{
	char			*sensitvity;
	char			*menu_name;
	t_menu_struct	param;
	
	ft_bzero(&param, sizeof(t_menu_struct));
	param.y = 600;
	param.idx = 1;
	sensitvity = ft_itoa(main->mouse_sensitivity);
	if (!sensitvity)
		exit_cub3d(main, "malloc failed in print current seinsitvity fonction");
	menu_name = ft_strjoin("CURRENT SENSITIVTY ", sensitvity);
	free(sensitvity);
	if (!menu_name)
		exit_cub3d(main, "malloc failed in print current seinsitvity fonction");
	print_menu_section(main, &param, menu_name);
	free(menu_name);
}

static void	print_minus_logo(t_main *main, int *menu)
{
	(void) menu;
	t_texture	logo;
	const char	*minus_logo_w = "Assets/fonts/logo/minus_white.xpm";

	logo.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, (char *)minus_logo_w,
		&logo.width, &logo.height);
	if (!logo.texture_ptr)
		exit_cub3d(main, "mlx load image failed in minus logo");
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, logo.texture_ptr, main->cal.half_ww + 50, 700);
}

static void	print_plus_logo(t_main *main, int *menu)
{
	(void) menu;
	t_texture	logo;
	const char	*plus_logo_w = "Assets/fonts/logo/plus_white.xpm";

	logo.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, (char *)plus_logo_w,
		&logo.width, &logo.height);
	if (!logo.texture_ptr)
		exit_cub3d(main, "mlx load image failed in plus logo");
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, logo.texture_ptr, main->cal.half_ww - 50 - 333 , 700);
}

void show_mouse_sensitivity_menu(t_main *main, int *menu)
{
	t_menu_struct	param;
	static int		menu_title = 0;

	ft_bzero(&param, (sizeof(t_menu_struct)));
	param.menu_size = 3;
	if (menu_title < 0)
		menu_title = 3;
	param.y = main->cal.half_wh - (param.menu_size * 48) + 250;
	param.selection = menu_title % param.menu_size;
	print_menu_title(main, "MOUSE SENSITIVITY");
	print_current_sensitivity(main);
	print_minus_logo(main, menu);
	print_plus_logo(main, menu);
	print_menu_section(main, &param, "RETURN");
	if (main->keys.enter)
		apply_selection(main, menu, param.selection, &menu_title);
	else if (main->keys.up)
		menu_up(main, &menu_title);
	else if (main->keys.down)
		menu_down(main, &menu_title);
}
