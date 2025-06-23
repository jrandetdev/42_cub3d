/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:40 by jrandet           #+#    #+#             */
/*   Updated: 2025/06/23 14:27:08 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
//#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int main()
{
	t_list *lst;

	lst = NULL;
	for (int i = 0; i < 3; i++)
		ft_lstadd_front(&lst, ft_lstnew(NULL));
	printf("the current length of the chained list is %d\n", ft_lstsize(lst));
	ft_lstadd_front(&lst, ft_lstnew(NULL));
	printf("the length is %d\n", ft_lstsize(lst));
	for (int d = 0; d < 2; d++)
		ft_lstadd_front(&lst, ft_lstnew(NULL));
	printf("the length after adding the 2 nodes is %d", ft_lstsize(lst));

	return (0);
}*/
