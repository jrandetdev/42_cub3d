/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:11:00 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 21:17:25 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_main *main)
{
	main->menu = 1;
	main->param.fov = 1;
	main->param.show_minimap = 1;
	main->interaction.mouse.sensitivity = 25;
	main->interaction.mouse.x = WIN_WIDTH / 2;
	if (gettimeofday(&main->bonus.last_sec, NULL))
		print_error_syscall(main, "GetTimeOfDay failed in init_cub3d");
}