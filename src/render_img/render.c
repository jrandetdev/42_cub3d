/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:55:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/12 16:36:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		dda.camera_x = 2 * thread->start / (float)WIN_WIDTH - 1;
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

static void	pre_calc(t_main *main)
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

static void	wait_threads(t_threads *threads, int created_threads)
{
	int	i;

	i = 0;
	while (i < created_threads)
		pthread_join(threads[i++].thread_id, NULL);
}

static void	create_threads(t_main *main)
{
	int			i;
	int			segment;
	int			current_pos;
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
		if (pthread_create(&threads[i].thread_id, NULL
				, multi_cast_rays, &threads[i]))
			break ;
		i++;
	}
	wait_threads(threads, i);
	if (i != N_THREAD)
		print_error_syscall(main, "One or more threads failed");
}

void	cast_rays(t_main *main)
{
	int				x;
	t_dda_struct	dda_struct;
	t_texture		cardinal_texture;

	pre_calc(main);
	if (BONUS == 1 && N_THREAD > 1)
	{
		create_threads(main);
		return ;
	}
	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_bzero(&dda_struct, sizeof(t_dda_struct));
		dda_struct.camera_x = 2 * x / (float)WIN_WIDTH - 1;
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
