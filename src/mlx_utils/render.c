/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:17:18 by hdougoud          #+#    #+#             */
/*   Updated: 2025/06/23 13:36:26 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_main *main)
{
	mlx_clear_window(main->mlx_ptr, main->mlx_win);
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win, main->image.data_img, 0, 0);
}