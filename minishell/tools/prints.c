/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:18:36 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/09/20 21:24:25 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_str_fd(int fd, char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(fd, &str[i], 1);
			i++;
		}
	}
}

void	print_tokens_list(t_token *tokens_list)
{
	int		i;
	t_token	*tmp;

	tmp = tokens_list;
	if (!tmp)
		return ;
	i = 0;
	printf("------------IMPRIMIENDO TOKENS-------------\n");
	while (tmp)
	{
		printf("El token numero[%d](%s) tiene tipo %d\n",
			i, tmp->str, tmp->type);
		i++;
		tmp = tmp->next;
	}
}

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	printf("\n");
}

void	print_string_to_stderror(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	print_sections_info(t_section *section)
{
	t_section	*tmp;
	t_file		*file;
	int			i;

	tmp = section;
	while (tmp)
	{
		file = tmp->files;
		i = 0;
		printf("Cmdv is:\n");
		print_matrix(tmp->cmdv);
		printf("\nthe right path is:\n");
		printf("\n%s\n\n", tmp->path);
		while (file)
		{
			printf("El file %d se llama %s\n", i, file->string);
			printf("El file %d tiene open mode %d\n", i, file->open_mode);
			printf("El fd_read es %d\n", tmp->fd_read);
			printf("El fd_write es %d\n", tmp->fd_write);
			printf("\n");
			file = file->next;
			i++;
		}
		tmp = tmp->next;
	}
}
