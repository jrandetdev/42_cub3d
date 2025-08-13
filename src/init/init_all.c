/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:57:29 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 21:17:30 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_all(t_main *main, int argc, char **argv)
{
	ft_bzero(main, sizeof(t_main));
	init_args(main, argc, argv);
	init_mlx(main);
	init_cub(main);
	init_img(main);
	init_external_events(main);
}
