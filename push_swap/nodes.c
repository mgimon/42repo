/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:16:50 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/04/30 16:50:34 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list_error(t_list **lst)
{
	t_list	*lst_temp;

	while (*lst != NULL)
	{
		lst_temp = (*lst)->next;
		free(*lst);
		*lst = lst_temp;
	}
	write(2, "Error\n", 6);
	exit(1);
}

t_list	*create_node(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*first_node(t_list *stack_a)
{
	if (!stack_a)
		return (NULL);
	while (stack_a->prev)
		stack_a = stack_a->prev;
	return (stack_a);
}

t_list	*get_last(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_ptr;

	lst_ptr = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (lst_ptr->next != NULL)
			lst_ptr = lst_ptr->next;
		lst_ptr->next = new;
		new->prev = lst_ptr;
	}
}
