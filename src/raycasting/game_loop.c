/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:55:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/30 18:04:22 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct	s_threads
{
	pthread_t	thread_id;
	int			start;
	int			end;
	t_main		*main;
}				t_threads;

static void	*multi_cast_rays(void *data)
{
	t_threads		*thread;
	t_dda_struct	dda;
	t_texture		cardinal_texture;
	t_main			*main;

	thread = (t_threads *)data;
	main = thread->main;
	while (thread->start < thread->end)
	{
		dda.camera_x = 2 * thread->start / (double)WIN_WIDTH - 1;
		dda.ray_dirx = main->player.dir_x
			+ main->player.plane_x * dda.camera_x;
		dda.ray_diry = main->player.dir_y
			+ main->player.plane_y * dda.camera_x;
		digital_differential_analyzer(main, &dda);
		cardinal_texture = get_corresp_texture(main, &dda);
		draw_texture(main, &dda, thread->start, cardinal_texture);
		thread->start++;
	}
	return (NULL);
}

static void	create_threads(t_main *main)
{
	int	i;
	int	segment;
	int	current_pos;
	int	created_threads;
	t_threads	threads[N_THREAD + 1];

	i = 0;
	current_pos = 0;
	segment = WIN_WIDTH / N_THREAD;
	ft_bzero(threads, sizeof(t_threads));
	while (i < N_THREAD)
	{
		threads[i].main = main;
		threads[i].start = current_pos;
		current_pos += segment;
		threads[i].end = current_pos;
		if (pthread_create(&threads[i].thread_id, NULL, multi_cast_rays, &threads[i]))
			exit_cub3d(main, "pthread_create failed");		
		i++;
	}
	created_threads = i;
	i = 0;
	while (i < created_threads)
		pthread_join(threads[i++].thread_id, NULL);
}

void	cast_rays(t_main *main)
{
	int				x;
	t_dda_struct	dda_struct;
	t_texture		cardinal_texture;

	x = 0;
	if (BONUS == 1 && N_THREAD > 1)
	{
		create_threads(main);
		return ;
	}
	while (x < WIN_WIDTH)
	{
		dda_struct.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		dda_struct.ray_dirx = main->player.dir_x
			+ main->player.plane_x * dda_struct.camera_x;
		dda_struct.ray_diry = main->player.dir_y
			+ main->player.plane_y * dda_struct.camera_x;
		digital_differential_analyzer(main, &dda_struct);
		cardinal_texture = get_corresp_texture(main, &dda_struct);
		draw_texture(main, &dda_struct, x, cardinal_texture);
		x++;
	}
}
