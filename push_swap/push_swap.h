/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:36:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/05/01 21:41:14 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				size;
	int				rot_u_cost;
	int				rev_u_cost;
	int				total_cost;
	int				direction;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	exit_with_error(void);
void	free_list_goodbye(t_list **lst);
void	error_checker(int argc, char **argv);
void	get_args(int argc, char **argv, t_list **new_node, t_list **stack_a);

// nodes.c
void	free_list_error(t_list **lst);
t_list	*create_node(int content);
t_list	*first_node(t_list *stack_a);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*get_last(t_list *lst);

// utils.c
void	ft_atoi_helper(char *str, t_list **lst, int *i, int *neg);
int		ft_atoi(char *str, t_list **lst);
int		ft_strcmp(char *s1, char *s2);
int		is_repeated_or_invalid(t_list *stack_a, int argv);
void	is_sorted(t_list **stack_a, int size);

// push.c
int		node_counter(t_list **lst);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

// swap.c
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	ss_swap(t_list **stack_a, t_list **stack_b);

// rotate.c
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rr_rotate(t_list **stack_a, t_list **stack_b);

// reverse.c
void	reverse_a(t_list **stack_a);
void	reverse_b(t_list **stack_b);
void	rrr_reverse(t_list **stack_a, t_list **stack_b);

// small_stack_sorting.c
void	small_stack_sorting(t_list **stack_a, t_list **stack_b);
void	a_sort_two(t_list **stack_a);
void	a_sort_four(t_list **stack_a, t_list **stack_b, int smallest);
void	a_sort_five(t_list **stack_a, t_list **stack_b, int smallest);

// median_sort_push.c
void	median_sort_push(t_list **stack_a, t_list **stack_b);
void	a_num_pusher(t_list **stack_a, t_list **stack_b, int median);
int		find_smallest(t_list **stack_a);
int		find_median(t_list **stack_a);
void	a_sort_three(t_list **stack_a);

// targets.c
void	reset_targets(t_list **stack_a, t_list **stack_b);
t_list	*go_find(t_list *tmp, int content);
t_list	*find_target(t_list **stack_a, int content);
int		find_biggest(t_list **stack_a);

// costs.c
void	set_u_costs(t_list **stack_a, t_list **stack_b);
void	set_costs_and_directions(t_list **stack_a, t_list **stack_b);
void	record_total_costs(t_list *target, t_list *tmp_b,
			int cost_a, int cost_b);
void	record_directions_and_costs(t_list *target, t_list *tmp_b);
void	reset_values(t_list **stack_a, t_list **stack_b);

// algorithm.c
void	raise_sorted_list_top(t_list **stack_a);
t_list	*find_cheapest(t_list **stack_b);
void	bring_optimals_separately(t_list **stack_a,
			t_list **stack_b, t_list *cheapest);
void	bring_optimals_jointly(t_list **stack_a,
			t_list **stack_b, t_list *cheapest);
void	refill_sort_a(t_list **stack_a, t_list **stack_b);

#endif
