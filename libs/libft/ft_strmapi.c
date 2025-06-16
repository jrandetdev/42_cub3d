/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:44:23 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/16 17:50:37 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi_string;
	unsigned int	i;

	if (!s)
		return (NULL);
	mapi_string = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mapi_string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapi_string[i] = (*f)(i, s[i]);
		i++;
	}
	mapi_string[i] = '\0';
	return (mapi_string);
}
