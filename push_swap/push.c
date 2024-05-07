/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:43 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 16:29:30 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_counter(t_list **lst)
{
	int		node_count;
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

void	push_a(t_list **stack_a, t_list **stack_b)
{
	int		size_a_before;
	int		size_b_before;
	t_list	*tmp;

	tmp = NULL;
	size_a_before = (*stack_a)->size;
	if (!(*stack_b))
		size_b_before = 0;
	else
		size_b_before = (*stack_b)->size;
	if (size_b_before > 0)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		(*stack_a)->size = size_a_before + 1;
		if (*stack_b != NULL)
			(*stack_b)->size = size_b_before - 1;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	int		size_a_before;
	int		size_b_before;
	t_list	*tmp;

	tmp = NULL;
	size_a_before = (*stack_a)->size;
	if (!(*stack_b))
		size_b_before = 0;
	else
		size_b_before = (*stack_b)->size;
	if (size_a_before > 0)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		(*stack_b)->size = size_b_before + 1;
		if (*stack_a != NULL)
			(*stack_a)->size = size_a_before - 1;
		write(1, "pb\n", 3);
	}
}
