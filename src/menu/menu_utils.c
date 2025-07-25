/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:51 by hdougoud          #+#    #+#             */
/*   Updated: 2025/07/22 15:49:40 by hdougoud         ###   ########.fr       */
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

char	ft_capitalize(char letter)
{
	if (letter >= 'A' || letter <= 'Z')
		return (letter);
	else
		return (letter -= 32);
}

void	menu_up(t_main *main, int *selection)
{
	*(selection) -= 1;
	main->keys.up = 0;
}

void	menu_down(t_main *main, int *selection)
{
	*(selection) += 1;
	main->keys.down = 0;
}
