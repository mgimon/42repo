/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:26:24 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 16:14:09 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_list **stack_a)
{
	t_list	*tmp;
	int		biggest;

	tmp = *stack_a;
	biggest = (*stack_a)->content;
	while (tmp != NULL)
	{
		if (tmp->content > biggest)
			biggest = tmp->content;
		tmp = tmp->next;
	}
	return (biggest);
}

t_list	*go_find(t_list *tmp, int content)
{
	int		number;
	t_list	*result;

	number = INT_MAX;
	while (tmp != NULL)
	{
		if (tmp->content > content && tmp->content < number)
		{
			result = tmp;
			number = tmp->content;
		}
		tmp = tmp->next;
	}
	return (result);
}

t_list	*find_target(t_list **stack_a, int content)
{
	t_list	*tmp;
	t_list	*target;
	int		smallest;
	int		biggest;

	smallest = find_smallest(stack_a);
	biggest = find_biggest(stack_a);
	tmp = *stack_a;
	if (smallest > content || biggest < content)
	{
		while (tmp != NULL)
		{
			if (tmp->content == smallest)
				return (tmp);
			tmp = tmp->next;
		}
	}
	target = go_find(tmp, content);
	return (target);
}

void	reset_targets(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp != NULL && *stack_a != NULL)
	{
		tmp->target = find_target(stack_a, tmp->content);
		tmp = tmp->next;
	}
}
