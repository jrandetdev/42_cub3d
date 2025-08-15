/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:22:41 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 16:03:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

#include <pthread.h>

# define N_THREAD 10

typedef struct s_main t_main;

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	int				value;
	bool			is_created;
}				t_mutex;

typedef struct s_threads
{
	pthread_t	thread_id;
	int			start;
	int			end;
	t_main		*main;
}				t_thread;

typedef struct s_global_threads
{
	short			created_threads;
	t_mutex			is_end;
	t_mutex			is_render;
	t_mutex			end_rendering;
	t_mutex			is_door_used;
	t_thread	thread[N_THREAD + 1];
}				t_global_threads;

void	init_threads(t_main *main);
void	join_threads(t_main *main);
void	*threads_routine(void *data);
void	destroy_all_mutex(t_main *main);
void	start_multi_threads_render(t_main *main);
void	*multi_cast_rays(t_thread *thread, t_main *main);

# endif