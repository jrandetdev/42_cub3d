/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 00:13:20 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/19 00:19:59 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

#if defined(__APPLE__)
	#define W 13
	#define A 0
	#define S 1
	#define D 2

#elif defined(__linux__)
	#define W
	#define A
	#define S
	#define D

#endif


#endif