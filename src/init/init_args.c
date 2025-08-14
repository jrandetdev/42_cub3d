/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:03:16 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 21:05:13 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_args(t_main *main, int argc, char **argv)
{
	if (argc != 2)
		print_error_message(main, "Please give only one file as input.");
	else if (!cub_extension_is_valid(argv[1], 3))
		print_error_message(main, ".cub extenssion is missing.");
	else if (WIN_HEIGHT < MIN_RESOLTION_Y || WIN_WIDTH < MIN_RESOLUTION_X)
		print_error_message(main, "Resolution too small");
}
