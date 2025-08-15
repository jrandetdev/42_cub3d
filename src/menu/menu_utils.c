/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:51 by hdougoud          #+#    #+#             */
/*   Updated: 2025/08/15 16:20:15 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_charjoin(char const *s1, char const s2)
{
	int		total_len;
	char	*result;

	if (!s1)
		return (NULL);
	total_len = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (total_len + 2));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	result[total_len] = s2;
	result[total_len + 1] = '\0';
	return (result);
}

void	menu_up_and_down(t_main *main, int *option_selected)
{
	if (main->interaction.keys.up)
	{
		*(option_selected) -= 1;
		main->interaction.keys.up = 0;
	}
	else
	{
		*(option_selected) += 1;
		main->interaction.keys.down = 0;
	}
}

void	put_letter(t_main *main, t_menu_display *params, char *file, int x)
{
	t_texture		letter;

	letter.ptr = mlx_xpm_file_to_image(main->mlx_ptr, file,
			&letter.width, &letter.height);
	if (!letter.ptr)
		print_error_syscall(main, "failed to load a letter in 'put_letter'");
	mlx_put_image_to_window(main->mlx_ptr, main->mlx_win,
		letter.ptr, x, params->y);
	mlx_destroy_image(main->mlx_ptr, letter.ptr);
}
