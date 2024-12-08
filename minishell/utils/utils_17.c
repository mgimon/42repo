/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_17.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:50:32 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/11/25 21:58:44 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_backdirs_only(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '/')
			return (0);
		if (str[i] == '.')
			count++;
		i++;
	}
	if (count > 3)
		return (count);
	return (0);
}

void	remove_backdirs(t_section *current, int dirs_back)
{
	int		i;
	char	*new_pwd;
	char	**split_pwd;
	char	**new_env;
	int		new_len;

	i = 0;
	if (!rembackdirs_hlpr(current, dirs_back, &i, &split_pwd))
		return ;
	new_len = 0;
	while (split_pwd[new_len] != NULL)
		new_len++;
	if (dirs_back >= new_len)
		new_len = 0;
	else
		new_len -= dirs_back;
	new_pwd = malloc(5 + 1);
	ft_strcpy(new_pwd, "PWD=");
	rembackdirs_hlpr_one(&new_pwd, &split_pwd, new_len);
	rembackdirs_hlpr_two(current, i, &new_env, &new_pwd);
	matrix_free(current->info->env);
	current->info->env = new_env;
	matrix_free(split_pwd);
}

void	if_backdirs_only(t_section *current)
{
	int	i;
	int	dirs_back;

	if (!is_backdirs_only(current->cmdv[1]))
		return ;
	i = is_backdirs_only(current->cmdv[1]);
	dirs_back = (i / 2) - 1;
	if (dirs_back > 1)
		dirs_back--;
	remove_backdirs(current, dirs_back);
}
