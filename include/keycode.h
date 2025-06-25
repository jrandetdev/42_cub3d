/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 00:13:20 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/24 20:55:44 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

#include "cub3d.h"

/* Common window dimensions */
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

#if defined(__APPLE__)

/* Event types for macOS */
enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

/* Mouse buttons for macOS */
enum e_mouse
{
	M_LEFT_CLICK = 1,
	M_RIGHT_CLICK = 2,
	M_MIDDLE_CLICK = 3,
	M_SCROLL_BACKWARD = 4,
	M_SCROLL_FORWARD = 5
};

/* Keyboard keys for macOS */
enum e_keys
{
	K_W = 13,
	K_S = 1,
	K_A = 0,
	K_D = 2,
	K_LEFT = 123,
	K_RIGHT = 124,
	K_UP = 126,
	K_DOWN = 125,
	K_ESCP = 53,
	K_C = 8,
	K_G = 5,        /* Added for consistency */
	K_K = 40,       /* Added for consistency */
	K_CTRL = 256
};

# define PLAYER_SPEED 7.0

#elif defined(__linux__)

# include <X11/X.h>

/* Event types for Linux */
enum e_events
{
	ON_KEYDOWN = KeyPress,
	ON_KEYUP = KeyRelease,
	ON_MOUSEDOWN = ButtonPress,
	ON_MOUSEUP = ButtonRelease,
	ON_MOUSEMOVE = MotionNotify,
	ON_EXPOSE = Expose,
	ON_DESTROY = DestroyNotify
};

/* Mouse buttons for Linux */
enum e_mouse
{
	M_LEFT_CLICK = 1,
	M_RIGHT_CLICK = 2,
	M_MIDDLE_CLICK = 3,
	M_SCROLL_BACKWARD = 4,
	M_SCROLL_FORWARD = 5
};

/* Keyboard keys for Linux */
enum e_keys
{
	K_W = 119,
	K_S = 115,
	K_A = 97,
	K_D = 100,
	K_LEFT = 65361,
	K_UP = 65362,
	K_RIGHT = 65363,
	K_DOWN = 65364,
	K_ESCP = 65307,
	K_C = 99,
	K_G = 103,
	K_K = 107,
	K_CTRL = 65507
};

# define PLAYER_SPEED 1.5

#endif

typedef struct s_main t_main;

/* Function prototypes */
void	init_keyboard_events(t_main *main);
int		key_handler(int key_code, t_main *main);

#endif