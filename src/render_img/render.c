/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:55:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:28:45 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pre_compute(t_main *main);

void	cast_rays(t_main *main)
{
	int				x;
	t_dda	dda;
	t_texture		cardinal_texture;

	x = 0;
	pre_compute(main);
	if (BONUS == 1 && N_THREAD >= 1)
	{
		start_multi_threads_render(main);
		return ;
	}
	while (x < WIN_WIDTH)
	{
		ft_bzero(&dda, sizeof(t_dda));
		dda.camera_x = 2 * x / (float)WIN_WIDTH - 1;
		dda.ray.x = main->player.dir_x
			+ main->player.plane_x * dda.camera_x;
		dda.ray.y = main->player.dir_y
			+ main->player.plane_y * dda.camera_x;
		digital_differential_analyzer(main, &dda, x);
		cardinal_texture = get_corresp_texture(main, &dda);
		draw_texture(main, &dda, x, cardinal_texture);
		x++;
	}
}

static void	pre_compute(t_main *main)
{
	t_cal	*cal;

	cal = &main->cal;
	cal->cf_ray_dirx_left = main->player.dir_x - main->player.plane_x;
	cal->cf_ray_diry_left = main->player.dir_y - main->player.plane_y;
	cal->cf_ray_dirx_right = main->player.dir_x + main->player.plane_x;
	cal->cf_ray_diry_right = main->player.dir_y + main->player.plane_y;
	cal->cf_pre_step_right = (main->cal.cf_ray_dirx_right
			- main->cal.cf_ray_dirx_left) / WIN_WIDTH;
	cal->cf_pre_step_down = (main->cal.cf_ray_diry_right
			- main->cal.cf_ray_diry_left) / WIN_WIDTH;
}

void	*multi_cast_rays(t_thread *thread, t_main *main)
{
	int				x;
	t_dda			dda;
	t_texture		cardinal_texture;

	x = thread->start;
	while (x < thread->end)
	{
		dda.camera_x = 2 * x / (float)WIN_WIDTH - 1;
		dda.ray.x= main->player.dir_x
			+ main->player.plane_x * dda.camera_x;
		dda.ray.y = main->player.dir_y
			+ main->player.plane_y * dda.camera_x;
		digital_differential_analyzer(main, &dda, x);
		cardinal_texture = get_corresp_texture(main, &dda);
		draw_texture(main, &dda, x, cardinal_texture);
		x++;
	}
	pthread_mutex_lock(&main->global_threads.end_rendering.mutex);
	main->global_threads.end_rendering.value += 1;
	pthread_mutex_unlock(&main->global_threads.end_rendering.mutex);
	return (NULL);
}

void	start_multi_threads_render(t_main *main)
{
	pthread_mutex_lock(&main->global_threads.is_render.mutex);
	main->global_threads.is_render.value = 1;
	pthread_mutex_unlock(&main->global_threads.is_render.mutex);
	while (1)
	{
		pthread_mutex_lock(&main->global_threads.end_rendering.mutex);
		if (main->global_threads.end_rendering.value == N_THREAD)
		{
			main->global_threads.end_rendering.value = 0;
			pthread_mutex_lock(&main->global_threads.is_render.mutex);
			main->global_threads.is_render.value = 0;
			pthread_mutex_unlock(&main->global_threads.is_render.mutex);
			pthread_mutex_unlock(&main->global_threads.end_rendering.mutex);
			return ;
		}
		pthread_mutex_unlock(&main->global_threads.end_rendering.mutex);
		usleep(50);
	}
}