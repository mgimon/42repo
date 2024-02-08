/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:41:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/03 20:00:19 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_ptr;

	lst_ptr = lst;
	if (lst_ptr == NULL)
		return (NULL);
	while (lst_ptr->next != NULL)
		lst_ptr = lst_ptr->next;
	return (lst_ptr);
}
