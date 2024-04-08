/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:36:42 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/04/08 22:17:24 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_atoi(char *str, t_list **lst);
t_list	*create_node(int content);
t_list	*add_node(t_list **node, int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_list_error(t_list **lst);
t_list	*first_node(t_list *stack_a);
int		is_repeated_or_invalid(t_list *stack_a, int argv);
void	get_args(int argc, char **argv, t_list **new_node, t_list **stack_a);
int		node_counter(t_list **lst);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	ss_swap(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

#endif
