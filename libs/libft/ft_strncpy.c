/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:05:54 by jvoisard          #+#    #+#             */
/*   Updated: 2025/06/16 17:50:37 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_strncpy(char *dst, char *src, size_t n)
{
	char	*cursor;

	if (!dst || !src)
		return ;
	cursor = dst;
	while (*src && n--)
		*cursor++ = *src++;
	*cursor = '\0';
}
