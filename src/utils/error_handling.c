/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:24:35 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/13 15:36:15 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error()
{
	printf("\033[0;31m");
	printf("Error\n");
	printf("\033[0m");
}

void	print_error_syscall(t_main *main, char *error_message)
{
	print_error();
	perror(error_message);
	exit_cub3d(main, 1);
}

void	print_error_message(t_main *main, char *error_message)
{
	print_error();
	ft_putendl_fd(error_message, 2);
	exit_cub3d(main, 1);
}
