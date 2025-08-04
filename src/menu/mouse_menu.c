/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:47 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/04 16:51:28 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	apply_selection(t_main *main, int *menu, int selection, int *menu_title)
{
	main->keys.enter = 0;
	if (selection == 0 && main->mouse.sensitivity < MAX_SENSITIVITY - 50)
		main->mouse.sensitivity += 1;
	else if (selection == 1 && main->mouse.sensitivity > MIN_SENSITIVITY)
		main->mouse.sensitivity -= 1;
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

static void	print_current_sensitivity(t_main *main)
{
	char			*sensitvity;
	char			*menu_name;
	t_menu_struct	param;
	
	ft_bzero(&param, sizeof(t_menu_struct));
	param.y = main->cal.half_wh - 316;
	param.idx = 1;
	sensitvity = ft_itoa(main->mouse.sensitivity);
	if (!sensitvity)
		exit_cub3d(main, "malloc failed in print current seinsitvity fonction");
	if (main->mouse.sensitivity >= 10)
		menu_name = ft_strjoin("CURRENT SENSITIVTY ", sensitvity);
	else
		menu_name = ft_strjoin("CURRENT SENSITIVTY 0", sensitvity);
	free(sensitvity);
	if (!menu_name)
		exit_cub3d(main, "malloc failed in print current seinsitvity fonction");
	print_menu_section(main, &param, menu_name);
	free(menu_name);
}

static void	print_minus_logo(t_main *main, int selection)
{
	t_texture	logo;
	char	*minus_logo_white = "Assets/fonts/logo/minus_white.xpm";
	char	*minus_logo_gold = "Assets/fonts/logo/minus_gold.xpm";

	if (selection == 1)
	{
		logo.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, minus_logo_gold,
			&logo.width, &logo.height);
	}
	else
	{
		logo.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, minus_logo_white,
			&logo.width, &logo.height);
	}
	if (!logo.texture_ptr)
		exit_cub3d(main, "mlx load image failed in minus logo");
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, logo.texture_ptr, main->cal.half_ww + 50, main->cal.half_wh - 250);
}

static void	print_plus_logo(t_main *main, int selection)
{
	t_texture	logo;
	char	*plus_logo_white = "Assets/fonts/logo/plus_white.xpm";
	char	*plus_logo_gold = "Assets/fonts/logo/plus_gold.xpm";

	if (selection == 0)
	{
		logo.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, plus_logo_gold,
			&logo.width, &logo.height);
	}
	else
	{
		logo.texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, plus_logo_white,
			&logo.width, &logo.height);
	}
	if (!logo.texture_ptr)
		exit_cub3d(main, "mlx load image failed in plus logo");
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, logo.texture_ptr, main->cal.half_ww - 50 - 128 , main->cal.half_wh - 250);
}

void show_mouse_sensitivity_menu(t_main *main, int *menu)
{
	t_menu_struct	param;
	static int		menu_title = 0;

	ft_bzero(&param, (sizeof(t_menu_struct)));
	param.menu_size = 3;
	if (menu_title < 0)
		menu_title = 2;
	param.y = main->cal.half_wh - (param.menu_size + 1 * 48);
	param.selection = menu_title % param.menu_size;
	print_menu_title(main, "MOUSE SENSITIVITY");
	print_current_sensitivity(main);
	print_minus_logo(main, param.selection);
	print_plus_logo(main, param.selection);
	param.idx = 2;
	print_menu_section(main, &param, "RETURN");
	if (main->keys.enter)
		apply_selection(main, menu, param.selection, &menu_title);
	else if (main->keys.up || main->keys.down)
		menu_up_and_down(main, &menu_title);
}
