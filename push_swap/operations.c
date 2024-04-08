/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:29:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/04/08 22:16:48 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	int		node_count;
	t_list	*tmp;

	node_count = node_counter(stack_a);
	if (node_count > 1)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (tmp == NULL)
			exit(1);
		tmp->content = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp->content;
		free(tmp);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_list **stack_b)
{
	int		node_count;
	t_list	*tmp;

	node_count = node_counter(stack_b);
	if (node_count > 1)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		if (tmp == NULL)
			exit(1);
		tmp->content = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = tmp->content;
		free(tmp);
		write(1, "sb\n", 3);
	}
}

void	ss_swap(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	int		node_count;
	t_list	*tmp;

	tmp = NULL;
	node_count = node_counter(stack_b);
	if (node_count > 0)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	int		node_count;
	t_list	*tmp;

	tmp = NULL;
	node_count = node_counter(stack_a);
	if (node_count > 0)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		write(1, "pb\n", 3);
	}
}

