/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:14:44 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/04/08 22:18:30 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
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
		is_argv_invalid = is_repeated_or_invalid(*stack_a, ft_atoi(*argv, stack_a));
		if (is_argv_invalid > 0)
			free_list_error(stack_a);
		*new_node = create_node(ft_atoi(*argv, stack_a));
		if (!new_node)
			free_list_error(stack_a);
		ft_lstadd_back(stack_a, *new_node);
		argv++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*new_node;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_b = create_node(4);
	stack_b->next = create_node(1);
	get_args(argc, argv, &new_node, &stack_a);
	printf("\n Stack_a contiene: \n");
	print_list(stack_a);
	printf("\n Stack_b contiene: \n");
	print_list(stack_b);

	printf("\n-----------------------------------\n");
	push_b(&stack_a, &stack_b);
	printf("-----------------------------------\n");

	printf("\n Stack_a contiene: \n");
	print_list(stack_a);
	printf("\n Stack_b contiene: \n");
	print_list(stack_b);
	
	return (0);
}
