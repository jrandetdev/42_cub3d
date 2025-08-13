/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:40:25 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/13 22:30:14 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_main t_main;

void		parsing(t_main *main, char *file);
void		check_if_dir(t_main *main, char *file_relative_path);
bool		cub_extension_is_valid(char	*s, int len);
bool		xmp_extension_is_valid(char	*s, int len);
bool		is_valid_colour(t_main *main, char **splitted_colours);
bool		find_player_position(t_main *main, int *x, int *y, int *player);
char		*max_strdup(const char *s1, int max_size);
void		extract_file_elements(t_main *main, char *file, char ***fc);
void		is_map_valid(t_main *main);
void		parse_map_elements(t_main *main, char **file_content);
void		get_map_descritpion(t_main *main, char **file_content);
void		load_personal_textures(t_main *main);
void		extract_colour(t_main *main, char *id, char *info);
void		extract_texture(t_main *main, char *id, char *xpm_f);
void		get_texture_data(t_main *main, t_texture *direc, char *xpm_file);
void		check_and_get_texture(t_main *main, t_texture *pannel,
				char *filename);

#endif