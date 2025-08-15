/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:06:42 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 17:19:17 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
//#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	temp = (*lst);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
