/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:57:29 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 15:49:46 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_all(t_main *main, int argc, char **argv)
{
	init_args(main, argc, argv);
	init_mlx_ptr(main);
	init_cub(main);
	init_img(main);
	init_threads(main);
}
