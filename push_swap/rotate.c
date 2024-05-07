/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:58 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 15:57:00 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	int		size_a;
	t_list	*tmp;
	t_list	*last;

	if (!(*stack_a))
		return ;
	size_a = (*stack_a)->size;
	if (size_a > 1)
	{
		(*stack_a)->size = 0;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		last = get_last(*stack_a);
		tmp->next = NULL;
		last->next = tmp;
		(*stack_a)->size = size_a;
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_list **stack_b)
{
	int		size_b;
	t_list	*tmp;
	t_list	*last;

	if (!(*stack_b))
		return ;
	size_b = (*stack_b)->size;
	if (size_b > 1)
	{
		(*stack_b)->size = 0;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		last = get_last(*stack_b);
		tmp->next = NULL;
		last->next = tmp;
		(*stack_b)->size = size_b;
		write(1, "rb\n", 3);
	}
}

static void	aux_rotate_a(t_list **stack_a)
{
	int		size_a;
	t_list	*tmp;
	t_list	*last;

	if (!(*stack_a))
		return ;
	size_a = (*stack_a)->size;
	if (size_a > 1)
	{
		(*stack_a)->size = 0;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		last = get_last(*stack_a);
		tmp->next = NULL;
		last->next = tmp;
		(*stack_a)->size = size_a;
	}
}

static void	aux_rotate_b(t_list **stack_b)
{
	int		size_b;
	t_list	*tmp;
	t_list	*last;

	if (!(*stack_b))
		return ;
	size_b = (*stack_b)->size;
	if (size_b > 1)
	{
		(*stack_b)->size = 0;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		last = get_last(*stack_b);
		tmp->next = NULL;
		last->next = tmp;
		(*stack_b)->size = size_b;
	}
}

void	rr_rotate(t_list **stack_a, t_list **stack_b)
{
	aux_rotate_a(stack_a);
	aux_rotate_b(stack_b);
	write(1, "rr\n", 3);
}
