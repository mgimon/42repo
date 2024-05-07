/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:14:28 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 15:56:18 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_list **stack_a)
{
	int		size_a;
	t_list	*last;
	t_list	*prev_last;

	size_a = (*stack_a)->size;
	if (size_a > 1)
	{
		(*stack_a)->size = 0;
		last = *stack_a;
		prev_last = NULL;
		while (last->next != NULL)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		(*stack_a)->size = size_a;
		write(1, "rra\n", 4);
	}
}

void	reverse_b(t_list **stack_b)
{
	int		size_b;
	t_list	*last;
	t_list	*prev_last;

	if (!(*stack_b))
		return ;
	size_b = (*stack_b)->size;
	if (size_b > 1)
	{
		(*stack_b)->size = 0;
		last = *stack_b;
		prev_last = NULL;
		while (last->next != NULL)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		(*stack_b)->size = size_b;
		write(1, "rrb\n", 4);
	}
}

static void	aux_reverse_a(t_list **stack_a)
{
	int		size_a;
	t_list	*last;
	t_list	*prev_last;

	size_a = (*stack_a)->size;
	if (size_a > 1)
	{
		(*stack_a)->size = 0;
		last = *stack_a;
		prev_last = NULL;
		while (last->next != NULL)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		(*stack_a)->size = size_a;
	}
}

static void	aux_reverse_b(t_list **stack_b)
{
	int		size_b;
	t_list	*last;
	t_list	*prev_last;

	if (!(*stack_b))
		return ;
	size_b = (*stack_b)->size;
	if (size_b > 1)
	{
		(*stack_b)->size = 0;
		last = *stack_b;
		prev_last = NULL;
		while (last->next != NULL)
		{
			prev_last = last;
			last = last->next;
		}
		prev_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		(*stack_b)->size = size_b;
	}
}

void	rrr_reverse(t_list **stack_a, t_list **stack_b)
{
	aux_reverse_a(stack_a);
	aux_reverse_b(stack_b);
	write(1, "rrr\n", 4);
}
