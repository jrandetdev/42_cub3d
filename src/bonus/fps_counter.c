/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:27:23 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/23 11:25:07 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fps_counter(t_main *main)
{
	unsigned int		ms;
	struct timeval		current;
	static unsigned int	frames = 0;
	char				*str_frame;

	frames++;
	if (gettimeofday(&current, NULL))
		exit_cub3d(main, "GetTimeOfDay failed in fps counter");
	ms = (main->bonus.last_sec->tv_sec - current.tv_sec) / 1000;
	ms += (main->bonus.last_sec->tv_usec - current.tv_usec) * 1000;
	if (ms >= 1000)
	{
		main->bonus.fps = frames;
		frames = 0;
		if (gettimeofday(main->bonus.last_sec, NULL))
			exit_cub3d(main, "GetTimeOfDay failed in fps counter");
	}
	str_frame = ft_itoa(main->bonus.fps); //optimisation
	mlx_string_put(main->mlx_ptr, main->mlx_win, 10, 10, 0xff1100, str_frame);
	free(str_frame);
}