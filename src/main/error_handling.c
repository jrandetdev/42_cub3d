/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:24:35 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/22 16:24:47 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_and_message(char *error_message)
{
	printf("\033[0;31m");
	printf("Error\n");
	printf("\033[0m");
	ft_putendl_fd(error_message, 2);
}
