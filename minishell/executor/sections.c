/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:37:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/02 21:24:24 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//printf("Section found. Contains %d files\n\n", n);
void	set_files_section(t_section *section, t_token *first, int s)
{
	t_token	*tmp;
	t_file	*files;
	int		n;
	int		i;

	i = 0;
	tmp = get_first_in_section(first, s);
	n = count_files_per_section(tmp);
	if (n == 0)
	{
		section->files = NULL;
		return ;
	}
	files = malloc(sizeof(t_file) * n);
	while (tmp && tmp->type != 7)
	{
		if (tmp->next && tmp->type >= 3 && tmp->type <= 5)
			add_file_to_files(tmp, files, &i, n);
		tmp = tmp->next;
	}
	section->files = files;
	open_files_section(section);
}

void	set_cmdv_section(t_section *section, t_token *first, int s)
{
	t_token	*tmp;
	char	**cmdv;
	int		i;

	i = 0;
	tmp = get_first_in_section(first, s);
	cmdv = malloc(sizeof(char *) * (count_cmdvs_per_section(tmp) + 1));
	while (tmp && tmp->type != 7)
	{
		if (tmp->type == 1)
		{
			cmdv[i] = tmp->str;
			i++;
			tmp = tmp->next;
			while (tmp && tmp->type == 2)
			{
				cmdv[i] = tmp->str;
				i++;
				tmp = tmp->next;
			}
			break ;
		}
		tmp = tmp->next;
	}
	set_cmdv_section_helper(section, cmdv, i);
}

void	init_section_objects(t_general *info,
t_token *first, t_section *section, int s)
{
	int	i;

	i = 0;
	init_section_objects_helper(section, first, s);
	idontevenknow_bro(info, &section);
	if (info->paths)
	{
		if (info->paths[i])
		{
			while (info->paths[i])
				i++;
		}
		section->paths = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (info->paths[i])
		{
			section->paths[i] = ft_strdup(info->paths[i]);
			i++;
		}
		section->paths[i] = NULL;
		set_cmd_in_paths(section);
		set_path(section);
	}
	else
		section->paths = NULL;
}

void	init_section_all_null(t_section *section)
{
	section->fd_read = -1;
	section->fd_write = -1;
	section->env = NULL;
	section->paths = NULL;
	section->path = NULL;
	section->cmdv = NULL;
	section->heredocs = NULL;
	section->files = NULL;
	section->nofile = 0;
}

t_section	*create_sections_list(t_general *info)
{
	int			i;
	int			n;
	t_section	*sections_list;

	i = 0;
	n = count_sections(info->tokens_list);
	if (!n)
		return (NULL);
	sections_list = malloc(sizeof(t_section) * n);
	while (i < n)
	{
		if (i == (n - 1))
			sections_list[i].next = NULL;
		else
			sections_list[i].next = &sections_list[i + 1];
		init_section_all_null(&sections_list[i]);
		i++;
	}
	i = 0;
	while (i < n)
	{
		init_section_objects(info, info->tokens_list, &sections_list[i], i);
		i++;
	}
	return (sections_list);
}
