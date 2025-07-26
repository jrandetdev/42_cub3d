/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:10:09 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/26 22:10:13 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calcule_constants(t_main *main)
{
	main->cal.half_wh = WIN_HEIGHT / 2;
	main->cal.half_ww = WIN_WIDTH / 2;
	main->cal.pre_fov = (FOV / 2) * (M_PI / 180);
}
