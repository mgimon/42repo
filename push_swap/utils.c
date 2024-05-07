/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:35:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 21:41:54 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_repeated_or_invalid(t_list *stack_a, int argv)
{
	t_list	*tmp;

	tmp = first_node(stack_a);
	while (tmp)
	{
		if (tmp->content == argv || tmp->content > 2147483647)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (-1);
}

void	ft_atoi_helper(char *str, t_list **lst, int *i, int *neg)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
	{
		if (str[*i] < '0' || str[*i] > '9')
		{
			if ((*lst) != NULL)
				free_list_error(lst);
			exit(1);
		}
		(*i)++;
	}
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*neg *= -1;
		(*i)++;
	}
}

int	ft_atoi(char *str, t_list **lst)
{
	int	i;
	int	neg;
	int	res;
	int	prev_res;

	i = 0;
	neg = 1;
	res = 0;
	ft_atoi_helper(str, lst, &i, &neg);
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev_res = res;
		res = (str[i] - '0') + (res * 10);
		if (res < prev_res && res != -2147483648)
			free_list_error(lst);
		i++;
	}
	if (str[i] != '\0' && (*lst) != NULL)
		free_list_error(lst);
	else if (str[i] == ' ')
		exit(1);
	else if (str[i] != '\0')
		exit_with_error();
	return (res * neg);
}

void	is_sorted(t_list **stack_a, int size)
{
	t_list	*tmp;
	int		n;
	int		i;

	tmp = *stack_a;
	n = tmp->content;
	tmp = tmp->next;
	i = 0;
	while (i < size && tmp != NULL)
	{
		if (tmp->content > n)
		{
			n = tmp->content;
			tmp = tmp->next;
		}
		else if (tmp->content < n)
			return ;
		i++;
	}
	exit(1);
}
