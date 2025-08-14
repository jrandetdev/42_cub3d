/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:03:49 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 23:25:05 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

typedef struct s_main t_main;

void	init_all(t_main *main, int argc, char **argv);
void	init_args(t_main *main, int argc, char **argv);
void	init_mlx(t_main *main);
void	init_cub(t_main *main);
void	init_img(t_main *main);

#endif