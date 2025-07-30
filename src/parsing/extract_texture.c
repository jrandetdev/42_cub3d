/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:20:40 by jrandet           #+#    #+#             */
/*   Updated: 2025/07/30 16:37:49 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_all_door_textures(t_main *main)
{
	int			i;
	char		*num;
	char		*filename;
	char		*fullname;
	const char	*path = "Assets/textures/doors/door_";

	i = 0;
	while (i < 5)
	{
		num = ft_itoa(i);
		if (!num)
			exit_cub3d(main, "itoa failed in load_doors_textures");
		filename = ft_strjoin(path, num);
		free(num);
		if (!filename)
			exit_cub3d(main, "first ft_strjoin failed in load_doors_textures");
		fullname = ft_strjoin(filename, ".xpm");
		free(filename);
		if (!fullname)
			exit_cub3d(main, "second ft_strjoin failed in load_doors_textures");
		get_texture_data(main, &main->animation.door[i], fullname);
		free(fullname);
		i++;
	}
	main->animation.door[i].texture_ptr = NULL;
}

void	get_texture_data(t_main *main, t_texture *direc, char *xpm_file)
{
	direc->texture_ptr = mlx_xpm_file_to_image(main->mlx_ptr, xpm_file, \
		&direc->width, &direc->height);
	if (!direc->texture_ptr)
	{
		perror("texture failed");
		exit_cub3d(main, "Texture path not found or invalid.");
	}
	printf("%p\n", direc->texture_ptr);
	direc->texture.addr = mlx_get_data_addr(
			direc->texture_ptr,
			&direc->texture.bitspp,
			&direc->texture.size_line,
			&direc->texture.endian);
	if (!direc->texture.addr)
		exit_cub3d(main, "Mlx_get_data_addr failed.");
	direc->texture.bytespp = direc->texture.bitspp / 8;
	direc->texture.pixels_per_line = \
		direc->texture.size_line / direc->texture.bytespp;
	direc->texture.total_bytes = direc->texture.size_line * direc->height;
}

void	extract_texture(t_main *main, char *id, char *xpm_f)
{
	if (!xmp_extension_is_valid(xpm_f, 3))
		return (exit_cub3d(main, "Texture file needs xpm extension."));
	if (ft_strncmp(id, "NO", 2) == 0)
		return (get_texture_data(main, &main->texture_bank.no, xpm_f));
	else if (ft_strncmp(id, "SO", 2) == 0)
		return (get_texture_data(main, &main->texture_bank.so, xpm_f));
	else if (ft_strncmp(id, "WE", 2) == 0)
		return (get_texture_data(main, &main->texture_bank.we, xpm_f));
	else if (ft_strncmp(id, "EA", 2) == 0)
		return (get_texture_data(main, &main->texture_bank.ea, xpm_f));
	else
		return (exit_cub3d(main, "Texture id needs NO, SO, WE, EA"));
}

void	check_and_get_texture_data(t_main *main, t_texture *pannel, char *filename)
{
	if (!xmp_extension_is_valid(filename, 3))
		return (exit_cub3d(main, "Texture file needs xpm extension."));
	get_texture_data(main, pannel, filename);
}

void	load_personal_textures(t_main *main)
{
	check_and_get_texture_data(main, &main->texture_bank.floor, "./Assets/textures/floor.xpm");
	check_and_get_texture_data(main, &main->texture_bank.ceiling, "./Assets/textures/Star_Ceiling-7.xpm");
	load_all_door_textures(main);
}
