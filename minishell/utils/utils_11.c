/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:35:51 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/10/30 11:46:13 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_export_var(t_section *current, char ***new_paths, int n)
{
	char	*str;

	str = ft_strjoin("declare -x ", current->cmdv[n]);
	add_str_to_matrix(&current->info->exports, str);
	free(str);
	if (ft_strchr(current->cmdv[n], '='))
	{
		if_remove_var_from_env(&current->info->env, current->cmdv[n]);
		add_str_to_matrix(&current->info->env, current->cmdv[n]);
		if (ft_strncmp_pipex(current->cmdv[n], "PATH=", 5) == 0)
		{
			if (*new_paths != NULL)
				matrix_free(*new_paths);
			*new_paths = ft_split(current->cmdv[n], ':');
		}
		if (*new_paths != NULL)
		{
			if (current->info->paths != NULL)
				matrix_free(current->info->paths);
			current->info->paths = *new_paths;
		}
	}
}

//*prev_dir[1] = '\0';
char	*get_pdir_helper(size_t len, char **pwd, char **prev_dir)
{
	size_t	i;
	size_t	k;

	i = len;
	while (i > 0)
	{
		if (*pwd[i - 1] == '/')
			break ;
		i--;
	}
	if (i == 0)
	{
		*prev_dir = (char *)malloc(2 * sizeof(char));
		*prev_dir[0] = '.';
		return (*prev_dir[1] = '\0', *prev_dir);
	}
	*prev_dir = (char *)malloc((i + 1) * sizeof(char));
	k = 0;
	while (k < i)
	{
		*prev_dir[k] = *pwd[k];
		k++;
	}
	*prev_dir[i] = '\0';
	return (*prev_dir);
}

int	has_slash(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	i--;
	i--;
	while (i > 0)
	{
		if (str[i] == '/')
			return (1);
		i--;
	}
	return (0);
}

int	has_content(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != '\0' && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	n_all(char **cmdv)
{
	int	k;

	k = 1;
	if (!cmdv)
		return (1);
	if (!cmdv[0])
		return (1);
	if (!cmdv[1])
		return (1);
	while (cmdv[k])
	{
		if ((ft_strcmp(cmdv[k], "-n") != 0) && (has_content(cmdv[k])))
			return (0);
		k++;
	}
	return (1);
}
