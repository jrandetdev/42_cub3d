/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:23:10 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 13:34:29 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

bool	is_only_space(char *line);
void	null_terminate_line(char **line);
char	**copy_map(t_map *map);

#endif