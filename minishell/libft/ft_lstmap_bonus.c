/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:58:48 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/05 12:24:12 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	link_nodes(t_list **new_list, t_list *new_node, t_list *lst_ptr)
{
	new_node->next = NULL;
	if (*new_list == NULL)
		*new_list = new_node;
	else
		lst_ptr->next = new_node;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*lst_ptr;
	t_list	*new_node;

	new_list = NULL;
	while (lst != NULL)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		if (new_node->content == NULL)
		{
			free(new_node);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		link_nodes(&new_list, new_node, lst_ptr);
		lst_ptr = new_node;
		lst = lst->next;
	}
	return (new_list);
}
