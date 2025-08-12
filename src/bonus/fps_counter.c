/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:27:23 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/12 14:15:41 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fps_counter(t_main *main)
{
	unsigned int		ms;
	struct timeval		current;
	static unsigned int	frames = 0;
	char				*str_frame;

	frames += 1;
	if (gettimeofday(&current, NULL))
		print_error_syscall(main, "GetTimeOfDay in fps counter");
	ms = (current.tv_sec - main->bonus.last_sec.tv_sec) * 1000;
	ms += (current.tv_usec - main->bonus.last_sec.tv_usec) / 1000;
	if (ms >= 1000)
	{
		main->bonus.fps = frames;
		frames = 0;
		if (gettimeofday(&main->bonus.last_sec, NULL))
			print_error_syscall(main, "GetTimeOfDay in fps counter");
	}
	str_frame = ft_itoa(main->bonus.fps);
	if (!str_frame)
		print_error_message(main, "itoa failed");
	mlx_string_put(main->mlx_ptr, main->mlx_win, 10, 10, 0xff1100, str_frame);
	free(str_frame);
}
