/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:09:52 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/12 16:36:55 by jrandet          ###   ########.fr       */
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
	float	opening_pourcent;
	int		pos_x;
	int		pos_y;
}	t_door;

typedef struct s_menu_struct
{
	int	y;
	int	idx;
	int	selection;
	int	menu_size;
}	t_menu_struct;

typedef struct s_menu_param
{
	bool		fov;
	bool		show_fps;
	bool		sensitivity;
	bool		show_minimap;
	bool		show_minimap_grid;
}				t_menu_param;

#endif