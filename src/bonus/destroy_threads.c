/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:51:41 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 18:14:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_error_and_skip(char *error_message);
static void	safe_destroy_mutex(t_mutex *mutex);

void	join_threads(t_main *main)
{
	int	i;

	i = 0;
	errno = 0;
	pthread_mutex_lock(&main->global_threads.is_end.mutex);
	main->global_threads.is_end.value = 1;
	pthread_mutex_unlock(&main->global_threads.is_end.mutex);
	while (i < main->global_threads.created_threads)
	{
		errno = pthread_join(main->global_threads.thread[i++].thread_id, NULL);
		if (errno)
			print_error_and_skip("pthread_join failed");
	}
}

void	destroy_all_mutex(t_main *main)
{
	safe_destroy_mutex(&main->global_threads.is_door_used);
	safe_destroy_mutex(&main->global_threads.is_end);
	safe_destroy_mutex(&main->global_threads.is_render);
	safe_destroy_mutex(&main->global_threads.end_rendering);
}

static void	safe_destroy_mutex(t_mutex *mutex)
{
	if (!mutex->is_created)
		return ;
	errno = pthread_mutex_destroy(&mutex->mutex);
	if (errno)
		print_error_and_skip("pthread_mutex_destroy failed");
}

static void	print_error_and_skip(char *error_message)
{
	print_error();
	perror(error_message);
	ft_putendl_fd("\033[0;33m""the program will continue to try"
		" to release the rest of the resources correctly""\033[0m", 2);
	errno = 0;
}
