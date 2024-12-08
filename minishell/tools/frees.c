/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:56:25 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/07 21:41:36 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	matrix_free(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_files(t_file *files)
{
	t_file	*current;
	t_file	*next;

	current = files;
	while (current != NULL)
	{
		next = current->next;
		if (current->string)
		{
			free(current->string);
			current->string = NULL;
		}
		current = next;
	}
}

void	free_sections_list(t_section *first)
{
	t_section	*first_ptr;
	t_section	*tmp;

	if (!first)
		return ;
	first_ptr = first;
	while (first)
	{
		tmp = first->next;
		if (first->files)
			free_files(first->files);
		free(first->files);
		if (first->paths)
			matrix_free(first->paths);
		free(first->cmdv);
		free(first->path);
		first = tmp;
	}
	free(first_ptr);
}

void	free_tokens_list(t_token *first)
{
	t_token	*current;
	t_token	*next_node;

	current = first;
	next_node = NULL;
	while (current)
	{
		next_node = current->next;
		if (current->str)
			free(current->str);
		free(current);
		current = next_node;
	}
	first = NULL;
}

void	free_info(t_general *info)
{
	if (info->env)
		matrix_free(info->env);
	if (info->exports)
		matrix_free(info->exports);
	if (info->paths)
		matrix_free(info->paths);
}
