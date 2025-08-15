/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:43:57 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 18:04:33 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*is_this_the_end(t_main *main);

void	*threads_routine(void *data)
{
	t_main			*main;
	t_thread		*thread;

	thread = (t_thread *)data;
	main = thread->main;
	while (1)
	{
		is_this_the_end(main);
		pthread_mutex_lock(&main->global_threads.is_render.mutex);
		if (main->global_threads.is_render.value == 1)
		{
			pthread_mutex_unlock(&main->global_threads.is_render.mutex);
			multi_cast_rays(thread, main);
			while (1)
			{
				pthread_mutex_lock(&main->global_threads.is_render.mutex);
				if (!main->global_threads.is_render.value)
					break ;
				pthread_mutex_unlock(&main->global_threads.is_render.mutex);
				usleep(50);
			}
		}
		pthread_mutex_unlock(&main->global_threads.is_render.mutex);
		usleep(50);
	}
}

static void	*is_this_the_end(t_main *main)
{
	pthread_mutex_lock(&main->global_threads.is_end.mutex);
	if (main->global_threads.is_end.value == 1)
	{
		pthread_mutex_unlock(&main->global_threads.is_end.mutex);
		return (NULL);
	}
	pthread_mutex_unlock(&main->global_threads.is_end.mutex);
	return (NULL);
}
