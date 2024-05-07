/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:54:32 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 15:59:25 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_sort_four(t_list **stack_a, t_list **stack_b, int smallest)
{
	while ((*stack_a)->content != smallest)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	a_sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	a_sort_five(t_list **stack_a, t_list **stack_b, int smallest)
{
	if ((*stack_a)->content != smallest && ((*stack_a)->next)->content
		!= smallest && (((*stack_a)->next)->next)->content != smallest)
	{
		while ((*stack_a)->content != smallest)
			reverse_a(stack_a);
	}
	else
	{
		while ((*stack_a)->content != smallest)
			rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	smallest = find_smallest(stack_a);
	a_sort_four(stack_a, stack_b, smallest);
	push_a(stack_a, stack_b);
}

void	a_sort_two(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->content > (tmp->next)->content)
		swap_a(stack_a);
}

void	small_stack_sorting(t_list **stack_a, t_list **stack_b)
{
	int	smallest;

	smallest = find_smallest(stack_a);
	if ((*stack_a)->size == 2)
	{
		a_sort_two(stack_a);
		exit(0);
	}
	else if ((*stack_a)->size == 3)
	{
		a_sort_three(stack_a);
		exit(0);
	}
	else if ((*stack_a)->size == 4)
	{
		a_sort_four(stack_a, stack_b, smallest);
		exit(0);
	}
	else if ((*stack_a)->size == 5)
	{
		a_sort_five(stack_a, stack_b, smallest);
		exit(0);
	}
}
