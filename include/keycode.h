/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 00:13:20 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/19 10:48:22 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

#if defined(__APPLE__)

enum
{
	K_W = 13,
	K_S = 1,
	K_A = 0,
	K_D = 2,
	K_LEFT = 123,    // Changed from 124
	K_RIGHT = 124,   // Changed from 123
	K_UP = 126,      // Changed from 125
	K_DOWN = 125,    // Changed from 126
	K_ESCP = 53,
	K_C = 8,
	K_CTRL = 256
};

# elif __linux__ 
#	include <mlx.h>
#	include <X11/X.h>
#	define WIN_WIDTH 800
#	define WIN_HEIGHT 800
#	define SCALE 4
#	define ZOOM 0.2
#	define COL_TAB_SIZE 16
#	define MAX_ITER	250
enum // events for macos 
{
	ON_KEYDOWN		= KeyPress,
	ON_KEYUP		= KeyRelease,
	ON_MOUSEDOWN	= ButtonPress,
	ON_MOUSEUP		= ButtonRelease,
	ON_MOUSEMOVE	= MotionNotify,
	ON_EXPOSE		= Expose,
	ON_DESTROY		= DestroyNotify,
};

enum // mouse clicks for macos 
{
	M_LEFT_CLICK		= 1,
	M_RIGHT_CLICK		= 2,
	M_MIDDLE_CLICK		= 3,
	M_SCROLL_BACKWARD	= 4,
	M_SCROLL_FORWARD	= 5,
};

enum
{
	K_W		= 119,
	K_S		= 115,
	K_LEFT	= 65361,
	K_UP	= 65362,
	K_RIGHT	= 65363,
	K_DOWN	= 65364,
	K_ESCP	= 65307,
	K_C		= 99,
	K_CTRL	= 65507,
};
# endif

#endif