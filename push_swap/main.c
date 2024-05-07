/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:14:44 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/06 19:41:31 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_list_goodbye(t_list **lst)
{
	t_list	*lst_temp;

	while (*lst != NULL)
	{
		lst_temp = (*lst)->next;
		free(*lst);
		*lst = lst_temp;
	}
}

void	get_args(int argc, char **argv, t_list **new_node, t_list **stack_a)
{
	int		is_argv_invalid;

	is_argv_invalid = -1;
	if (argc == 1 || argc == 0)
		exit(1);
	argv++;
	while (*argv)
	{
		is_argv_invalid = is_repeated_or_invalid(*stack_a,
				ft_atoi(*argv, stack_a));
		if (is_argv_invalid > 0)
			free_list_error(stack_a);
		*new_node = create_node(ft_atoi(*argv, stack_a));
		if (!new_node)
			free_list_error(stack_a);
		ft_lstadd_back(stack_a, *new_node);
		argv++;
	}
}

void	error_checker(int argc, char **argv)
{
	char	*str;
	int		i;

	i = 1;
	str = argv[i];
	if (argc == 2)
	{
		if (ft_strcmp(str, "2147483648") == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "") == 0 || ft_strcmp(argv[i], "-") == 0
			|| ft_strcmp(argv[i], "+") == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*new_node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_a = NULL;
	stack_b = NULL;
	error_checker(argc, argv);
	get_args(argc, argv, &new_node, &stack_a);
	size_a = node_counter(&stack_a);
	stack_a->size = size_a;
	is_sorted(&stack_a, size_a);
	small_stack_sorting(&stack_a, &stack_b);
	median_sort_push(&stack_a, &stack_b);
	refill_sort_a(&stack_a, &stack_b);
	raise_sorted_list_top(&stack_a);
	free_list_goodbye(&stack_a);
	return (0);
}
