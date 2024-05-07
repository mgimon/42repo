/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:58:33 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 16:00:10 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	int		size_a;
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	size_a = (*stack_a)->size;
	if (size_a > 1)
	{
		(*stack_a)->size = 0;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = (*stack_a)->next;
		(*stack_a)->next = tmp;
		(*stack_a)->size = size_a;
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_list **stack_b)
{
	int		size_b;
	t_list	*tmp;

	if (!(*stack_b))
		return ;
	size_b = (*stack_b)->size;
	if (size_b > 1)
	{
		(*stack_b)->size = 0;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = (*stack_b)->next;
		(*stack_b)->next = tmp;
		(*stack_b)->size = size_b;
		write(1, "sb\n", 3);
	}
}

static void	aux_swap_a(t_list **stack_a)
{
	int		size_a;
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	size_a = (*stack_a)->size;
	if (size_a > 1)
	{
		(*stack_a)->size = 0;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = (*stack_a)->next;
		(*stack_a)->next = tmp;
		(*stack_a)->size = size_a;
	}
}

static void	aux_swap_b(t_list **stack_b)
{
	int		size_b;
	t_list	*tmp;

	if (!(*stack_b))
		return ;
	size_b = (*stack_b)->size;
	if (size_b > 1)
	{
		(*stack_b)->size = 0;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = (*stack_b)->next;
		(*stack_b)->next = tmp;
		(*stack_b)->size = size_b;
	}
}

void	ss_swap(t_list **stack_a, t_list **stack_b)
{
	aux_swap_a(stack_a);
	aux_swap_b(stack_b);
	write(1, "ss\n", 3);
}
