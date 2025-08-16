/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:49:05 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/16 16:32:39 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "cub3d.h"
# if defined (__linux__)
#  include <X11/X.h>
# endif

/* Common window dimensions */

# if defined(__APPLE__)

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
	K_UP = 126,
	K_RIGHT = 124,
	K_DOWN = 125,
	K_ESCP = 53,
	K_E = 14,
	K_C = 8,
	K_G = 5,
	K_K = 40,
	K_M = 46,
	K_CTRL = 256,
	K_ENTER = 36,
	K_SHIFT = 257,
	K_P = 35
};
#  define MIN_RESOLUTION_X 1280
#  define MIN_RESOLTION_Y 720
#  define PLAYER_SPEED 0.04
#  define ROTATION_SPEED 0.02
#  define WIN_WIDTH 1664
#  define WIN_HEIGHT 936
#  define FOV 66

# elif defined(__linux__)

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
	K_W			= 119,
	K_S			= 115,
	K_A			= 97,
	K_D			= 100,
	K_LEFT		= 65361,
	K_UP		= 65362,
	K_RIGHT		= 65363,
	K_DOWN		= 65364,
	K_ESCP		= 65307,
	K_E			= 101,
	K_C			= 99,
	K_G			= 103,
	K_K			= 107,
	K_M			= 109,
	K_CTRL		= 65507,
	K_ENTER		= 65293,
	K_SHIFT		= 65505,
	K_P			= 112,
};

#  define MIN_RESOLUTION_X 1920
#  define MIN_RESOLTION_Y 1080
#  define FOV 75
#  define PLAYER_SPEED 0.08
#  define ROTATION_SPEED 0.04
#  define WIN_WIDTH 3800
#  define WIN_HEIGHT 2000

# endif

#endif