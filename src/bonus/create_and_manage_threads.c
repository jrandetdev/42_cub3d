/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_manage_threads.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:28:40 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 16:18:06 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	creates_threads(t_main *main);
static void	init_mutex(t_main *main, t_mutex *mutex);

void	init_threads(t_main *main)
{
	errno = 0;
	init_mutex(main, &main->global_threads.is_end);
	init_mutex(main, &main->global_threads.is_render);
	init_mutex(main, &main->global_threads.is_door_used);
	init_mutex(main, &main->global_threads.end_rendering);
	creates_threads(main);
}

static void	init_mutex(t_main *main, t_mutex *mutex)
{
	errno = pthread_mutex_init(&mutex->mutex, NULL);
	if (errno)
		print_error_syscall(main, "pthreads_mutex_init failed");
	(*mutex).value = 0;
	(*mutex).is_created = 1;
}

static void	creates_threads(t_main *main)
{
	int			i;
	int			segment;
	int			current_pos;

	i = 0;
	current_pos = 0;
	segment = WIN_WIDTH / N_THREAD;
	ft_bzero(main->global_threads.thread, sizeof(t_thread));
	while (i < N_THREAD)
	{
		main->global_threads.thread[i].main = main;
		main->global_threads.thread[i].start = current_pos;
		current_pos += segment;
		main->global_threads.thread[i].end = current_pos;
		errno = pthread_create(&main->global_threads.thread[i].thread_id, NULL
				, threads_routine, &main->global_threads.thread[i]);
		if (errno)
			print_error_syscall(main, "pthread_create failed");
		i++;
	}
	main->global_threads.created_threads = i;
}
