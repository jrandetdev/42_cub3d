/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:39:24 by jrandet           #+#    #+#             */
/*   Updated: 2025/08/15 17:19:35 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
//#include <stdio.h>

t_list	*ft_newnode_start(void *new_content)
{
	t_list	*new_node;

	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		free(new_content);
		return (NULL);
	}
	return (new_node);
}

t_list	*ft_newnode(t_list **head, t_list **new_head, void *(*f)(void *),
					void (*del)(void *))
{
	void	*new_content;
	t_list	*new_node;

	new_content = f((*head)->content);
	if (!new_content)
	{
		ft_lstclear(new_head, del);
		return (NULL);
	}
	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		del(new_content);
		ft_lstclear(new_head, del);
		return (NULL);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *head, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;
	t_list	*current;

	if (!head || !f || !del)
		return (NULL);
	new_node = ft_newnode_start(f(head->content));
	if (!new_node)
		return (NULL);
	new_head = new_node;
	current = new_head;
	head = head->next;
	while (head)
	{
		new_node = ft_newnode(&head, &new_head, f, del);
		if (!new_node)
			return (ft_lstclear(&new_head, del), NULL);
		current->next = new_node;
		current = current->next;
		head = head->next;
	}
	return (new_head);
}
