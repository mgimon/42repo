/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:28:20 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/02/03 19:36:55 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*lst_ptr;
	int		counter;

	counter = 0;
	lst_ptr = lst;
	while (lst_ptr != NULL)
	{
		lst_ptr = lst_ptr->next;
		counter++;
	}
	return (counter);
}
