/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:35:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/04/06 20:40:16 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_repeated_or_invalid(t_list *stack_a, int argv)
{
	t_list	*tmp;

	tmp = first_node(stack_a);
	while (tmp)
	{
		if (tmp->content == argv)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}

int	node_counter(t_list **lst)
{
	int	node_count;
	t_list	*i;

	if (!lst || !(*lst))
		return (0);
	node_count = 1;
	if (!(*lst)->next)
		return (1);
	i = first_node(*lst);
	while (i->next != NULL)
	{
		i = i->next;
		node_count++;
	}
	return (node_count);
}

int	ft_atoi(char *str, t_list **lst)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		if (str[i] < '0' || str[i] > '9')
			free_list_error(lst);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if (str[i] != '\0')
		free_list_error(lst);
	return (res * neg);
}
