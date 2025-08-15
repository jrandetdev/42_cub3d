/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:09:52 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 16:32:02 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_STRUCT_H
# define BONUS_STRUCT_H

# include <sys/time.h>

/*---------------------------------- ENUM ------------------------------------*/

enum e_menu
{
	NO_MENU = 0,
	MAIN_MENU = 1,
	PAUSE_MENU = 2,
	OPTION_MENU = 3,
	MOUSE_SENSITIVITY_OPTION = 4,
	FOV_OPTION = 5,
	DEBUG_MENU = 6,
};

enum e_main_menu
{
	PLAY = 0,
	OPTION = 1,
	DEBUG = 2,
	QUIT = 3,
};

/*--------------------------------- STRUCT -----------------------------------*/

typedef struct s_mouse
{
	float	x;
	float	dist;
	int		sensitivity;
}			t_mouse;

typedef struct s_bonus
{
	struct timeval	last_sec;
	unsigned int	fps;
}					t_bonus;

typedef struct s_door
{
	int		state;
	float	open_percent;
	int		pos_x;
	int		pos_y;
}	t_door;

typedef struct s_menu_display
{
	int		y;
	int		option_amount;
	int		option_selected;
	int		size;
	char	*top_menu_title;
	char	**menu_sections;
}	t_menu_display;

typedef struct s_menu_options
{
	bool		fov;
	bool		show_fps;
	bool		sensitivity;
	bool		show_minimap;
	bool		show_minimap_grid;
}				t_menu_options;

typedef struct s_menu
{
	short			current_menu;
	t_menu_options	option;
	t_menu_display	display;
}	t_menu;

#endif