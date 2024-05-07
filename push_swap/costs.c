/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:20:49 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 15:41:34 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_u_costs(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_b;
	while (tmp != NULL)
	{
		tmp->rot_u_cost = i;
		tmp->rev_u_cost = (*stack_b)->size - i;
		tmp = tmp->next;
		i++;
	}
	tmp = *stack_a;
	i = 0;
	while (tmp != NULL)
	{
		tmp->rot_u_cost = i;
		tmp->rev_u_cost = (*stack_a)->size - i;
		tmp = tmp->next;
		i++;
	}
}

void	record_total_costs(t_list *target, t_list *tmp_b,
		int cost_a, int cost_b)
{
	if (target->direction == tmp_b->direction)
	{
		if (cost_a > cost_b)
			tmp_b->total_cost = cost_a;
		else
			tmp_b->total_cost = cost_b;
	}
	else
		tmp_b->total_cost = cost_a + cost_b;
}

void	record_directions_and_costs(t_list *target, t_list *tmp_b)
{
	int	cost_a;
	int	cost_b;

	if (target->rev_u_cost < target->rot_u_cost)
	{
		cost_a = target->rev_u_cost;
		target->direction = -1;
	}
	else
	{
		cost_a = target->rot_u_cost;
		target->direction = 1;
	}
	if (tmp_b->rev_u_cost < tmp_b->rot_u_cost)
	{
		cost_b = tmp_b->rev_u_cost;
		tmp_b->direction = -1;
	}
	else
	{
		cost_b = tmp_b->rot_u_cost;
		tmp_b->direction = 1;
	}
	record_total_costs(target, tmp_b, cost_a, cost_b);
}

void	set_costs_and_directions(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;

	tmp_b = *stack_b;
	while (tmp_b != NULL)
	{
		tmp_a = *stack_a;
		while (tmp_a != NULL)
		{
			if (tmp_a == tmp_b->target)
			{
				record_directions_and_costs(tmp_a, tmp_b);
				break ;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

void	reset_values(t_list **stack_a, t_list **stack_b)
{
	reset_targets(stack_a, stack_b);
	set_u_costs(stack_a, stack_b);
	set_costs_and_directions(stack_a, stack_b);
}
