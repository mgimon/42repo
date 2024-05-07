/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:06:07 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 15:51:47 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_list **stack_a)
{
	t_list	*tmp;
	int		small;

	tmp = *stack_a;
	small = (*stack_a)->content;
	while (tmp != NULL)
	{
		if (tmp->content < small)
			small = tmp->content;
		tmp = tmp->next;
	}
	return (small);
}

int	find_median(t_list **stack_a)
{
	int		i;
	int		small;
	int		index;
	t_list	*tmp;

	i = 0;
	small = find_smallest(stack_a);
	while (i < (*stack_a)->size / 2)
	{
		tmp = *stack_a;
		small++;
		index = 0;
		while (index++ < (*stack_a)->size)
		{
			if (tmp->content == small)
				break ;
			tmp = tmp->next;
		}
		if (tmp != NULL)
		{
			small = tmp->content;
			i++;
		}
	}
	return (index - 1);
}

void	a_num_pusher(t_list **stack_a, t_list **stack_b, int median)
{
	int	j;
	int	i;
	int	set_once;

	j = (*stack_a)->size;
	i = 0;
	set_once = 0;
	while (j > 3)
	{
		push_b(stack_a, stack_b);
		if (set_once < 1)
		{
			(*stack_b)->size = 1;
			set_once++;
		}
		if ((*stack_b)->content > median)
			rotate_b(stack_b);
		j = (*stack_a)->size;
	}
}

void	a_sort_three(t_list **stack_a)
{
	if ((*stack_a)->content > ((*stack_a)->next)->content)
		swap_a(stack_a);
	if (((*stack_a)->next)->content > (((*stack_a)->next)->next)->content)
	{
		if ((*stack_a)->content > (((*stack_a)->next)->next)->content)
			reverse_a(stack_a);
		else
		{
			reverse_a(stack_a);
			swap_a(stack_a);
		}
	}
}

void	median_sort_push(t_list **stack_a, t_list **stack_b)
{
	int		median;
	int		index_median;
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	index_median = find_median(stack_a);
	while (i < index_median)
	{
		tmp = tmp->next;
		i++;
	}
	median = tmp->content;
	a_num_pusher(stack_a, stack_b, median);
	a_sort_three(stack_a);
}
