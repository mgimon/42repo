/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:58:10 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/03 21:26:29 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	}
}
