/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:24:00 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/10/29 18:19:51 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var_name(const char *var)
{
	char	*name;
	size_t	len;

	len = 0;
	while (var[len] && var[len] != '=')
		len++;
	name = (char *)malloc(len + 1);
	if (name)
	{
		ft_memcpy(name, var, len);
		name[len] = '\0';
	}
	return (name);
}

int	compare_var_name(const char *env_var, const char *var_name)
{
	while (*env_var && *env_var != '='
		&& *var_name && *env_var == *var_name)
	{
		env_var++;
		var_name++;
	}
	return (*env_var == '=' && *var_name == '\0');
}

char	*get_prev_dir(char **env)
{
	char	*pwd;
	char	*prev_dir;
	size_t	len;
	int		j;

	pwd = NULL;
	j = 0;
	while (env[j] != NULL)
	{
		if (ft_strncmp(env[j], "PWD=", 4) == 0)
		{
			pwd = env[j] + 4;
			break ;
		}
		j++;
	}
	if (pwd == NULL)
		return (NULL);
	len = ft_strlen(pwd);
	if (len == 0 || (len == 1 && pwd[0] == '/'))
	{
		prev_dir = (char *)malloc(2 * sizeof(char));
		return (prev_dir[0] = '.', prev_dir[1] = '\0', prev_dir);
	}
	return (get_pdir_helper(len, &pwd, &prev_dir));
}

char	*get_home(char **env)
{
	char	*home_value;
	int		i;
	size_t	j;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
		{
			home_value = (char *)malloc(ft_strlen(env[i] + 5) + 1);
			j = 0;
			while (env[i][j + 5] != '\0')
			{
				home_value[j] = env[i][j + 5];
				j++;
			}
			home_value[j] = '\0';
			return (home_value);
		}
		i++;
	}
	return (NULL);
}

int	n_valid_succession(char **cmdv, int *i)
{
	int	k;

	k = 1;
	if (!cmdv)
		return (0);
	if (!cmdv[0])
		return (0);
	while (cmdv[k])
	{
		if ((ft_strcmp(cmdv[k], "-n") != 0) && (has_content(cmdv[k])))
		{
			*i = k;
			return (1);
		}
		k++;
	}
	return (0);
}
