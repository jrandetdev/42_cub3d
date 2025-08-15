/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:40:25 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 16:08:55 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_main	t_main;

typedef struct s_flood_fill
{
	bool	is_invalid;
	int		height;
	int		width;
	char	**map;
}		t_flood_fill;

void		parsing(t_main *main, char *file);
void		check_if_file_is_dir(t_main *main, char *file_relative_path);
void		extract_file_elements(t_main *main, char *file, char ***fc);
void		check_for_tabs(t_main *main, char **file_content);
bool		cub_extension_is_valid(char	*s, int len);
bool		xmp_extension_is_valid(char	*s, int len);
void		assign_floor_ceiling_text(t_main *main, char *id, char *filename);
void		extract_colour_and_texture(t_main *main, char **file_content);
void		get_texture_data(t_main *main, t_texture *direc, char *xpm_file);
bool		is_valid_colour(t_main *main, char **splitted_colours);
void		get_map_dimensions(t_main *main, t_map *map, char **file_cont);
bool		find_player_position(t_main *main, int *x, int *y, int *player);
char		*max_strdup(const char *s1, int max_size);
void		check_if_map_is_valid(t_main *main);
void		extract_map_from_file(t_main *main, char **file_cont);
void		ft_flood_fill(t_main *main, t_flood_fill *flood_fill, int x, int y);
void		extract_colour(t_main *main, char *id, char *info);
void		extract_texture(t_main *main, char *id, char *xpm_f);
void		get_texture_data(t_main *main, t_texture *direc, char *xpm_file);
void		load_personal_texture(t_main *main, t_texture *pannel,
				char *filename);

#endif