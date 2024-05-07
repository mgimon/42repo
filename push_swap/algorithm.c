/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:15:40 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 15:32:45 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheapest(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*cheapest;

	tmp = *stack_b;
	cheapest = tmp;
	while (tmp != NULL)
	{
		if (tmp->total_cost < cheapest->total_cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

void	raise_sorted_list_top(t_list **stack_a)
{
	int		smallest;
	int		i;
	int		j;
	t_list	*tmp;

	tmp = *stack_a;
	smallest = find_smallest(stack_a);
	i = 0;
	j = 0;
	while (tmp->content != smallest)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < (*stack_a)->size / 2)
	{
		while (j++ < i)
			rotate_a(stack_a);
	}
	else
	{
		while (j++ < ((*stack_a)->size - i))
			reverse_a(stack_a);
	}
}

void	bring_optimals_separately(t_list **stack_a, t_list **stack_b,
		t_list *cheapest)
{
	while (*stack_a != cheapest->target)
	{
		if ((cheapest->target)->direction == 1)
			rotate_a(stack_a);
		else
			reverse_a(stack_a);
	}
	while (*stack_b != cheapest)
	{
		if (cheapest->direction == 1)
			rotate_b(stack_b);
		else
			reverse_b(stack_b);
	}
}

void	bring_optimals_jointly(t_list **stack_a, t_list **stack_b,
		t_list *cheapest)
{
	if (cheapest->direction == cheapest->target->direction)
	{
		if (cheapest->direction == 1)
		{
			while (*stack_b != cheapest && *stack_a != cheapest->target)
				rr_rotate(stack_a, stack_b);
		}
		else if (cheapest->direction == -1)
		{
			while (*stack_b != cheapest && *stack_a != cheapest->target)
				rrr_reverse(stack_a, stack_b);
		}
	}
}

void	refill_sort_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	while (*stack_b != NULL)
	{
		reset_values(stack_a, stack_b);
		cheapest = find_cheapest(stack_b);
		bring_optimals_jointly(stack_a, stack_b, cheapest);
		bring_optimals_separately(stack_a, stack_b, cheapest);
		push_a(stack_a, stack_b);
	}
}
